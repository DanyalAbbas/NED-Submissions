"""Train a small, browser-exportable version of the final model and dump it to JSON.

The demo mirrors the project pipeline: same cleaned data, same features, same 80/20
stratified split (seed 42), median imputation + scaling for numerics and one-hot
encoding for categories. It then fits a compact gradient-boosting classifier and
exports the trees so the site can score orders entirely in JavaScript.
"""
import json
from pathlib import Path

import numpy as np
import pandas as pd
from sklearn.compose import ColumnTransformer
from sklearn.ensemble import GradientBoostingClassifier
from sklearn.impute import SimpleImputer
from sklearn.metrics import accuracy_score, roc_auc_score
from sklearn.model_selection import train_test_split
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import OneHotEncoder, StandardScaler

RANDOM_STATE = 42
ROOT = Path(__file__).resolve().parent
DATA = ROOT.parent / "data" / "Ecommerce_Delivery_cleaned.csv"

WEATHER = {"Clear": 0, "Cloudy": 1, "Extreme Heat": 2, "Rain": 3, "Storm": 4, "Snow": 5}
PRIORITY = {"Urgent": 0, "High": 1, "Normal": 2, "Low": 3}


def add_features(frame):
    frame = frame.copy()
    frame["weather_severity"] = frame["weather_condition"].map(WEATHER)
    frame["priority_rank"] = frame["order_priority"].map(PRIORITY)
    frame["distance_per_promised_day"] = frame["distance_km"] / frame["promised_delivery_days"].clip(lower=1)
    return frame.drop(columns=["order_date"])


df = pd.read_csv(DATA)
y = (df["late_delivery"] == "Yes").astype(int)
X = add_features(df.drop(columns=["late_delivery"]))

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=RANDOM_STATE, stratify=y
)

num_cols = X_train.select_dtypes("number").columns.tolist()
cat_cols = X_train.select_dtypes("object").columns.tolist()

prep = ColumnTransformer([
    ("num", Pipeline([("impute", SimpleImputer(strategy="median")),
                      ("scale", StandardScaler())]), num_cols),
    ("cat", Pipeline([("impute", SimpleImputer(strategy="most_frequent")),
                      ("onehot", OneHotEncoder(handle_unknown="ignore", sparse_output=False))]), cat_cols),
])
prep.fit(X_train)

Xtr = prep.transform(X_train)
Xte = prep.transform(X_test)

model = GradientBoostingClassifier(
    n_estimators=150, learning_rate=0.05, max_depth=3,
    subsample=0.9, random_state=RANDOM_STATE,
)
model.fit(Xtr, y_train)

prob = model.predict_proba(Xte)[:, 1]
print(f"demo model — test ROC-AUC {roc_auc_score(y_test, prob):.4f}  "
      f"accuracy {accuracy_score(y_test, prob >= 0.5):.4f}")

# ---- export preprocessing ----
names = prep.get_feature_names_out()
scaler = prep.named_transformers_["num"].named_steps["scale"]
imputer = prep.named_transformers_["num"].named_steps["impute"]
encoder = prep.named_transformers_["cat"].named_steps["onehot"]

columns = []
for name, mean, scale, median in zip(names[:len(num_cols)], scaler.mean_, scaler.scale_,
                                     imputer.statistics_):
    columns.append({"name": name, "type": "num", "feature": name.split("__", 1)[1],
                    "mean": float(mean), "scale": float(scale), "median": float(median)})

offset = len(num_cols)
for j, feature in enumerate(cat_cols):
    for k, category in enumerate(encoder.categories_[j]):
        columns.append({"name": names[offset], "type": "cat", "feature": feature,
                        "category": str(category), "mode": str(df[feature].mode()[0])})
        offset += 1

# ---- export trees ----
trees = []
for est in model.estimators_.ravel():
    t = est.tree_
    trees.append({
        "feature": t.feature.tolist(),
        "threshold": [round(float(v), 6) for v in t.threshold],
        "left": t.children_left.tolist(),
        "right": t.children_right.tolist(),
        "value": [round(float(v[0][0]), 8) for v in t.value],
    })

baseline = float(model._raw_predict_init(Xte[:1])[0][0])
raw = baseline + model.learning_rate * sum(
    est.predict(Xte[:1])[0] for est in model.estimators_.ravel()
)
check = model.decision_function(Xte[:1])[0]
print(f"inference check: exported {raw:.6f} vs sklearn {check:.6f}")
assert abs(raw - check) < 1e-6

# ---- UI metadata ----
def levels(col):
    counts = df[col].value_counts()
    return [str(c) for c in counts.index]


def num_range(col):
    return {
        "min": float(np.floor(df[col].min())),
        "max": float(np.ceil(df[col].max())),
        "median": float(df[col].median()),
        "q05": float(df[col].quantile(0.05)),
        "q95": float(df[col].quantile(0.95)),
        "step": 1.0,
    }


ui = {
    "weather_condition": levels("weather_condition"),
    "order_priority": levels("order_priority"),
    "shipping_method": levels("shipping_method"),
    "distance_km": num_range("distance_km"),
    "promised_delivery_days": num_range("promised_delivery_days"),
    "warehouse_processing_hours": num_range("warehouse_processing_hours"),
    "shipping_cost_usd": num_range("shipping_cost_usd"),
}

payload = {
    "metric": {
        "roc_auc": round(float(roc_auc_score(y_test, prob)), 4),
        "accuracy": round(float(accuracy_score(y_test, prob >= 0.5)), 4),
        "base_rate": round(float(y.mean()), 4),
        "trees": len(trees),
        "features": len(columns),
        "train_rows": int(len(y_train)),
        "test_rows": int(len(y_test)),
    },
    "baseline": baseline,
    "learning_rate": float(model.learning_rate),
    "columns": columns,
    "trees": trees,
    "ui": ui,
}

out = ROOT / "assets" / "model.json"
out.write_text(json.dumps(payload, separators=(",", ":")))
print(f"wrote {out} ({out.stat().st_size/1024:.0f} KB) — {len(trees)} trees, {len(columns)} encoded columns")
print("UI levels:", {k: (v if isinstance(v, list) else "numeric") for k, v in ui.items()})

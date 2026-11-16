# CT-368 — Phase 1 and Phase 2

**Late Delivery Risk Prediction in E-Commerce Logistics**
Dataset: *E-Commerce Delivery & Shipping Data 2026* (Kaggle) — 50,000 orders × 30 columns.
Group member: Danyal Abbas, CT-24084.

## Submit these files

| File | What it is |
|---|---|
| `CT24084.ipynb` | The notebook, fully executed (47 cells, 26 code) — Phase 1 and Phase 2 |
| `CT24084_ProjectReport.pdf` | The project report (18 pages, both phases) |
| `data/Ecommerce_Delivery_raw.csv` | Original Kaggle download, never modified |
| `data/Ecommerce_Delivery_cleaned.csv` | Cleaned data: 50,000 × 19, zero missing values |

`CT24084.html` and `report.html` are rendered copies for reading.

## What is in the notebook

| Phase | Section | Brief | Done |
|---|---|---|---|
| 1 | §1 Features and target | 2 | All 30 columns explained; target `late_delivery`; identifiers vs leakage vs features |
| 1 | §2 Data quality | 3 | Target balance, distributions, correlation, missing values, duplicates, dtype, future dates, $500 cap, IQR outliers with revenue impact, leakage demo (`delivery_delay_days` alone → AUC 1.0000) |
| 1 | §3 Cleaning | 4 | Type fix, 4 identifier columns and 8 leakage columns dropped, `shipping_cost_capped` added, cleaned CSV saved |
| 1 | §4 Train/test split | 5 | 80/20, `stratify=y`, `random_state=42` |
| 1 | §5 Preprocessing & selection | 6 | 3 engineered features; impute + scale + one-hot; `SelectKBest(mutual_info_classif, k=15)`; logistic regression |
| 1 | §6 Class imbalance | 7 | 1.3:1, judged mild; class-weighted model compared on the same test set |
| 2 | §7 Problem and method | 1 | Classification, target, inputs, why ML, leakage protocol |
| 2 | §8 Training and CV | 2 | Logistic regression, decision tree, random forest, gradient boosting; 5-fold `StratifiedKFold` |
| 2 | §9 Evaluation | 3 | Comparison tables (CV + test), ROC-AUC bars, ROC curves, 4 confusion matrices |
| 2 | §10 Tuning | 4 | `GridSearchCV` on gradient boosting: `learning_rate` × `max_leaf_nodes`, before/after |
| 2 | §11 Results | 5 | Best/worst, over/underfitting, tuning effect, final test evaluation, limitations |
| 2 | §12–13 Conclusion and files | — | Summary, deliverables |

**Phase 1 result:** 0.882 ROC-AUC against a 0.563 majority-class baseline.
**Phase 2 result:** 0.898 test ROC-AUC (accuracy 0.804, F1 0.827, precision 0.820, recall 0.834).

## The website (`site/`)

`site/index.html` is a working demo, not a poster: a late-delivery risk calculator that runs the
model in the browser. Set weather, priority, shipping method, distance, promised days, processing
hours and shipping cost, and the page returns a risk percentage, a risk band, and a step-by-step
attribution of which fields moved the score and by how much.

It must be served over HTTP — browsers block `fetch()` on `file://` URLs, so the model JSON cannot
load if you double-click the file:

```bash
cd site
python3 -m http.server 8765
# open http://localhost:8765/
```

The model itself is exported by `site/export_model.py` (150 trees, 86 encoded columns, 40k/10k
split, test ROC-AUC 0.9031) into `site/assets/model.json`. It is a compact stand-in for the
report's final tuned model (0.898), trained the same way but with all encoded features kept so
that every control on the page can move the score. Re-run the export after any change to the data
or features:

```bash
cd site && python3.12 export_model.py
```

The page has no CDN or external dependency: one HTML file with inline CSS/JS plus local assets
(figures, report PDF, notebook, rendered HTML).

## Rebuilding

The notebook is generated from `make_notebook.py`, so edit that file rather than the `.ipynb`:

```bash
python3 make_notebook.py
jupyter nbconvert --to notebook --execute --inplace \
  --ExecutePreprocessor.kernel_name=py312 --ExecutePreprocessor.timeout=2400 CT24084.ipynb
jupyter nbconvert --to html CT24084.ipynb --output CT24084.html
```

The notebook needs the `py312` kernel (pandas, scikit-learn, matplotlib, seaborn). It is registered
with `python3.12 -m ipykernel install --user --name py312`.

The report is built from `report.md` (with `report.css`):

```bash
pandoc report.md -o report.html --standalone --embed-resources --css report.css --metadata lang=en
google-chrome --headless --disable-gpu --no-sandbox --no-pdf-header-footer \
  --print-to-pdf=CT24084_ProjectReport.pdf report.html
```

`archive/` holds the earlier, much longer draft and its scratch scripts. It is not part of the
submission and can be deleted.

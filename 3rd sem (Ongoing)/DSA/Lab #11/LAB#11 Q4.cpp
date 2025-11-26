#include<bits/stdc++.h>
using namespace std;

int main(void){
	vector<int>quality={10,20,5};
	vector<int>wage={70,50,30};
	int k=2;
	int n=quality.size();
	
	vector<pair<double,int>>workers;
	for(int i=0;i<n;i++){
		double ratio=(double) wage[i]/quality[i];
		workers.push_back({ratio,quality[i]});
	}
	
	sort(workers.begin(),workers.end());
	priority_queue<int>pq;
	int qualitysum=0;
	double mincost=1e18;
	
	for(int i=0;i<n;i++){
		pq.push(workers[i].second);
		qualitysum+=workers[i].second;
		
		if(pq.size()>k){
			qualitysum-=pq.top();
			pq.pop();
		}
		if(pq.size()==k){
			double ratio=workers[i].first;
			double cost=qualitysum*ratio;
			if(cost<mincost){
				mincost=cost;
			}
		}
	}
	cout<<mincost;
	return 0;
}
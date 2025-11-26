#include<iostream>
#include<map>
#include<vector>
using namespace std;

void heapify(pair<char,int>a[],int n,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	
	if(left<n && a[left].second>a[largest].second){
		largest=left;
	}
	if(right<n && a[right].second>a[largest].second){
		largest=right;
	}
	if(largest!=i){
		pair<char,int>temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		heapify(a,n,largest);
	}
}

int main(void){
	string s="cccaaa";
	map<int,int>freq;
	for(int i=0;i<s.length();i++){
		freq[s[i]]=freq[s[i]]+1;
	}
	int size=freq.size();
	pair<char,int>a[size];
	int idx=0;
	for(auto x:freq){
		a[idx].first=x.first;
		a[idx].second=x.second;
		idx++;
	}
	for(int i=size/2-1;i>=0;i--){
		heapify(a,size,i);
	}
	string result="";
	while(true){
		if(a[0].second==0)
			break;
			
		for(int i=0;i<a[0].second;i++){
			result=result+a[0].first;
		}
		a[0].second=0;
		heapify(a,size,0);
	}
	cout<<result;
	return 0;
}


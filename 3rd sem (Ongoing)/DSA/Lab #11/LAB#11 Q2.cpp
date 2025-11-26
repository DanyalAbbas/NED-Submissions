#include<iostream>
#include<map>
using namespace std;

void heapify(pair<int,int> a[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && a[left].second>a[largest].second)
        largest=left;
    if(right<n && a[right].second>a[largest].second)
        largest=right;

    if(largest!=i){
        pair<int,int> temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
}

int main(void){
    int nums[]={1,1,1,2,2,3};
    int n=sizeof(nums)/sizeof(nums[0]);
    int k=2;

    map<int,int> freq;
    for(int i=0;i<n;i++)
        freq[nums[i]]=freq[nums[i]]+1;

    int size=freq.size();
    pair<int,int> a[size];
    int idx=0;
    for(auto x:freq){
        a[idx].first=x.first;
        a[idx].second=x.second;
        idx++;
    }

    for(int i=size/2-1;i>=0;i--)
        heapify(a,size,i);

    for(int i=0;i<k;i++){
        cout<<a[0].first<<" ";
        a[0].second=0;
        heapify(a,size,0);
    }
    return 0;
}

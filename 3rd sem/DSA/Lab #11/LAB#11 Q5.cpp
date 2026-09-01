#include<bits/stdc++.h>
using namespace std;

vector<float> medianSlidingWindow(vector<int>& nums, int k){
    vector<float> res;
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;

    for(int i=0;i<nums.size();i++){
        if(lo.empty() || nums[i]<=lo.top()) lo.push(nums[i]);
        else hi.push(nums[i]);

        while(lo.size()>hi.size()+1){
            hi.push(lo.top());
            lo.pop();
        }
        while(hi.size()>lo.size()){
            lo.push(hi.top());
            hi.pop();
        }

        if(i>=k-1){
            if(k%2==0) res.push_back((lo.top()+hi.top())/2.0);
            else res.push_back(lo.top()*1.0);

            if(nums[i-k+1]<=lo.top()) lo.pop();
            else hi.pop();
        }
    }
    return res;
}

int main(void){
    vector<int> nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<float> ans=medianSlidingWindow(nums,k);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}

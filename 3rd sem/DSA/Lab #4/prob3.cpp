#include<bits/stdc++.h>
using namespace std;


// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.


void getPerms(vector<int>& nums,int idx, vector<vector<int>>& ans)
{
    if(idx == nums.size())
    {
        ans.push_back({nums});
        return;
    }
    for(int i = idx;i<nums.size();i++)
    {
        swap(nums[idx],nums[i]);
        getPerms(nums,idx+1,ans);
        swap(nums[idx],nums[i]);
    }
}
   
vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector<int>> ans;
    getPerms(nums,0,ans);
    return ans;
}


int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = permute(nums);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
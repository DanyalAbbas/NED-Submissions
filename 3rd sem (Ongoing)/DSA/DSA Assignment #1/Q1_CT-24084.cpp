#include <bits/stdc++.h>
using namespace std;

/* Given an array of integers and a target sum, find two numbers in the array that add up to
 the target sum. Return their indices. You can assume there will be exactly one so */


vector<int> findsum(vector<int>& nums, int target) 
{
    // To store the number and its index we will use a hash table
    unordered_map<int, int> map;

    // loop through the array
    for (int i = 0; i < nums.size(); i++) 
    {
        int remain = target - nums[i];
        if (map.find(remain) != map.end()) 
        {
            return {map[remain], i}; // Return index of the two numbers
        }
        // we are gona store the number with its index
        map[nums[i]] = i; 
    }
    // return nothing if no sum found
    return {};
}

int main()
{
    // for ex
    vector<int> nums = {1,4,5,6,7,8};
    
    vector<int> result = findsum(nums, 11);
    cout<<"The indices of the two numbers are: "<<result[0]<<" and "<<result[1]<<endl;
}
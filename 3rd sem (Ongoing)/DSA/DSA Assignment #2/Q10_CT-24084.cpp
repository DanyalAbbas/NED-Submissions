#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    deque<int> dq;   // stores indices, not values
    vector<int> ans;

    int n = nums.size();
    if (n == 0) return ans;

    for (int i = 0; i < n; i++) 
    {
        // Remove indices that are out of the current window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove smaller values (they can't be max if nums[i] is bigger)
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        // Add current index
        dq.push_back(i);

        // Add the current max (front of deque) to the answer once we have a full window
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }

        return ans;
}

int main()
{
    vector<int> nums = {1,2};
    int k = 2;
    vector<int> ans = maxSlidingWindow(nums, k);
    for (int i : ans)
        cout<<i<<" "<<endl;
}
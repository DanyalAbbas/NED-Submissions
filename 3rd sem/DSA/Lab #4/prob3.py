# vector<vector<int>> permute(vector<int>& nums) 
# {
#     vector<vector<int>> ans;
#     getPerms(nums,0,ans);
#     return ans;
# }


def getPerms(nums : list[int], idx : int, ans : list[list[int]]) -> None:
    if idx == len(nums):
        ans.append(nums)
        return
    
    for i in range(idx, len(nums)):
        nums[idx], nums[i] = nums[i], nums[idx]
        getPerms(nums, idx+1, ans)
        nums[idx], nums[i] = nums[i], nums[idx]

def permute(nums : list[int]):
    ans = []
    getPerms(nums, 0, ans)
    return ans

nums = [1,2,3]
ans = permute(nums)
print(ans)
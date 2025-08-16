// 90. Subsets II

// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

// Constraints:
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(0, {}, nums);
        return res;
    }
    void backtrack(int i, vector<int> subset,vector<int>& nums){
        res.push_back(subset);
        for(int j = i; j < nums.size(); j++){
            if(j > i && nums[j] == nums[j - 1]){
                continue;
            }
            subset.push_back(nums[j]);
            backtrack(j + 1, subset, nums);
            subset.pop_back();
        }
    }
};

// 78. Subsets

// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

// Constraints:
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current);

        for (int i = index; i < nums.size(); i++) {
            current.push_back(nums[i]);

            backtrack(i + 1, nums, current, result);

            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, nums, current, result);
        return result;
    }
    
};

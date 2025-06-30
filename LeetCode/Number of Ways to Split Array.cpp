//2270. Number of Ways to Split Array

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0, leftSum = 0;
        for (int num : nums){
            totalSum += num;
        }
        int count = 0;
        for (int i = 0; i < n - 1; ++i){
            leftSum += nums[i];
            long long rightSum = totalSum - leftSum;
            if (leftSum >= rightSum) {
                ++count;
            }
        }
        return count;
    }
};

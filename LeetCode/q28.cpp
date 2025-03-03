//494. Target Sum

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       int sum = accumulate(nums.begin(), nums.end(), 0);

       if ((sum + target) % 2 != 0 || sum + target < 0) {
        return 0;
       } 
       int P = (sum + target) / 2;

       vector<int> dp(P + 1, 0);
       dp[0] = 1;

       for (int num : nums) {
        for (int j = P; j >= num; --j) {
            dp[j] += dp[j - num];
        }
       }
       return dp[P];
    }
};
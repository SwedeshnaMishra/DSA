//689. Maximum Sum of 3 Non-Overlapping Subarrays

// Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
// Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

// Example 1:
// Input: nums = [1,2,1,2,6,7,5,1], k = 2
// Output: [0,3,5]
// Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
// We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically smaller.

// Example 2:
// Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
// Output: [0,2,4]
 
// Constraints:
// 1 <= nums.length <= 2 * 104
// 1 <= nums[i] < 216
// 1 <= k <= floor(nums.length / 3)

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int K) {
        int n = nums.size();
        vector<int> presum(n+1, 0);
        for (int i = 1; i <= n; i++) {
            presum[i] = presum[i-1] + nums[i-1];
        }
        vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(4, vector<int>(2, 0)));
        int mx = 0, pos = -1;
        for (int k = 1; k <= 3; k++) {
            for (int i = K; i <= n; i++) {
                dp[i][k][0] = dp[i-1][k][0];
                dp[i][k][1] = dp[i-1][k][1];
                int sumk = presum[i] - presum[i-K];
                if (dp[i][k][0]  < dp[i-K][k-1][0] + sumk) {             
                    dp[i][k][0] = dp[i-K][k-1][0] + sumk;
                    dp[i][k][1] = i;
                }
                if (dp[i][k][0] > mx) {
                    mx = dp[i][k][0];
                    pos = dp[i][k][1];
                }
            }
        }
        vector<int> result;
        for (int i = 3; i > 0; i--) {
            result.push_back(pos-K);
            pos = dp[pos-K][i-1][1];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

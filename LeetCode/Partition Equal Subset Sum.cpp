//416. Partition Equal Subset Sum

// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise. 

// Example 1:
// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

// Example 2:
// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
 
// Constraints:
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int total = 0;
            for (int num : nums) total += num;
    
            if (total % 2 != 0) return false; 
            int target = total / 2;
    
            vector<bool> dp(target + 1, false);
            dp[0] = true; 
    
            for (int num : nums) {
                for (int i = target; i >= num; --i) {
                    dp[i] = dp[i] || dp[i - num];
                }
            }
    
            return dp[target];
        }
    };

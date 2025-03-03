//2779. Maximum Beauty of an Array After Applying Operation

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int max_beauty = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            while (nums[right] - nums[left] > 2 * k) {
                ++left; 
            }
            max_beauty = max(max_beauty, right - left + 1);
        }
        
        return max_beauty;
    }
};
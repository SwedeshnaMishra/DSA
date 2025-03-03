//2425. Bitwise XOR of All Pairings

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xorResult = 0;
        if (nums2.size() % 2 != 0) {
            for (int num : nums1) {
                xorResult ^= num;
            }
        }
        if (nums1.size() % 2 != 0) {
            for (int num : nums2) {
                xorResult ^= num;
            }
        }
        return xorResult;
    }
};
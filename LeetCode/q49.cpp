//2683. Neighboring Bitwise XOR

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorSum = 0;
        for (int val : derived) {
            xorSum ^= val;
        }
        return xorSum == 0;
    }
};
//1422. Maximum Score After Splitting a String

class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        for (char c : s) {
            if (c == '1') totalOnes++;
        }

        int maxScore = 0, countLeftZeros = 0,countRightOnes = totalOnes;

        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') countLeftZeros++;
            else countRightOnes--;

            maxScore = max(maxScore, countLeftZeros + countRightOnes);
        }
        return maxScore;
    }
};
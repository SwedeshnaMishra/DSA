// 1014. Best Sightseeing Pair

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int maxLeft = values[0] + 0;

        for (int j = 1; j < values.size(); ++j) {
            maxScore = max(maxScore, maxLeft + values[j] - j);
            maxLeft = max(maxLeft, values[j] + j);
        }
        return maxScore;
    }
};
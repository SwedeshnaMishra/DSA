//1769. Minimum Number of Operations to Move All Balls to Each Box

class Solution {
public:
    vector<int> minOperations(string boxes) {
       int n = boxes.size();
       vector<int> result(n, 0);
       int moves = 0, balls = 0;

       for (int i = 0; i < n; ++i) {
        result[i] += moves;
        balls += (boxes[i] == '1');
        moves += balls;
       } 
       moves = 0;
       balls = 0;

       for (int i = n - 1; i >= 0; --i) {
        result[i] += moves;
        balls += (boxes[i] == '1');
        moves += balls;
       }
       return result;
    }
};

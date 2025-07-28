// 22. Generate Parentheses

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
// Input: n = 1
// Output: ["()"]
 
// Constraints:
// 1 <= n <= 8

class Solution {
public:

    void generateParenthesisHelper(int n, int open, int close, string current, vector<string>& result) {
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        if (open < n) {
            generateParenthesisHelper(n, open + 1, close, current + "(", result);
        }
        if (close < open) {
            generateParenthesisHelper(n, open, close + 1, current + ")", result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper(n, 0, 0, "", result);
        return result;
    }
};

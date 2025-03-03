//2116. Check if a Parentheses String Can Be Valid

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0)
        return false;

        int minOpen = 0, maxOpen = 0;

        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    minOpen++;
                    maxOpen++;
                } else {
                    minOpen = max(minOpen - 1, 0);
                    maxOpen--;
                }
            } else {
                minOpen = max(minOpen - 1, 0);
                maxOpen++;
            }
            if (maxOpen < 0) return false;
        }
        return minOpen == 0;
    }
};
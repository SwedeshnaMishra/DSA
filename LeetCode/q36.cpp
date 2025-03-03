//1930. Unique Length-3 Palindromic Subsequences

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_set<string> uniquePalindromes;
        vector<int> last(26, -1);
        vector<int> first(26, -1);

        for (int i = 0; i < n; ++i) {
            if (first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }
        for (char b = 'a'; b <= 'z'; ++b) {
            int l = first[b - 'a'];
            int r = last[b - 'a'];

            if (l != -1 && r != -1 && l < r) {
                unordered_set<char> leftChars;
                for (int i = l + 1; i < r; ++i) {
                    leftChars.insert(s[i]);
                }
                for (char a : leftChars) {
                    uniquePalindromes.insert(string({b, a, b}));
                }
            }
        }
        return uniquePalindromes.size();
    }
};
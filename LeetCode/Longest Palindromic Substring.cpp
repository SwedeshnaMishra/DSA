//5. Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.

// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:
// Input: s = "cbbd"
// Output: "bb"

// Constraints:
// 1 <= s.length <= 1000
// s consist of only digits and English letters.

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, maxLength = 0;

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                --left;
                ++right;
            }
            return right - left - 1;
        };
        for (int i = 0; i < n; ++i) {
            int len1 = expandAroundCenter(i, i);
            int len2 = expandAroundCenter(i, i + 1);
            int len = max(len1, len2);

            if(len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }            
        }
        return s.substr(start, maxLength);
    }
};

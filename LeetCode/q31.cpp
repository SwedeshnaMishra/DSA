//1639. Number of Ways to Form a Target String Given a Dictionary

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = target.size();
        int n = words[0].size();

        vector<vector<int>> freq(26, vector<int>(n, 0));
        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                freq[word[j] - 'a'][j]++;
            }
        }
        vector<int> dp(m + 1, 0);
        dp[0] = 1;

        for (int j = 0; j < n; ++j) {
            for (int i = m; i >= 1; --i) {
                char targetChar = target[i - 1];
                dp[i] = (dp[i] + (long long)dp[i - 1] * freq[targetChar - 'a'][j]) % MOD;
            }
        }
        return dp[m];
    }
};
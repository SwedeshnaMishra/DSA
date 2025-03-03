//2981. Find Longest Special Substring That Occurs Thrice I

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int result = -1;

        for (int len = 1; len <= n; ++len) {
            unordered_map<string, int> freq;

            for (int i = 0; i <= n - len; ++i) {
                string sub = s.substr(i, len);

                if (isSpecial(sub)) {
                    freq[sub]++;
                }
            }

            for (const auto& [sub, count] : freq) {
                if (count >= 3) {
                    result = len; 
                }
            }
        }

        return result;
    }


private:
    bool isSpecial(const string& str) {
        char first = str[0];
        for (char c : str) {
            if (c != first) return false;
        }
        return true;
    }
};
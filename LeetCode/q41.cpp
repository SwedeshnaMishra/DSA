//2185. Counting Words With a Given Prefix

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        int prefLength = pref.size();

        for (const string& word : words) {
            if (word.substr(0, prefLength) == pref) {
                count++;
            }
        }
        return count;
    }
};
// 2381. Shifting Letters II

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);

        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            if (direction == 1) {
                diff[start] += 1;
                diff[end + 1] -= 1;
            } else {
                diff[start] -= 1;
                diff[end + 1] += 1;
            }
        }
        vector<int> netShift(n, 0);
        int shift = 0;
        for (int i = 0; i < n; ++i) {
            shift += diff[i];
            netShift[i] = shift;
        }
        for (int i = 0; i < n; ++i) {
            int currentShift = (netShift[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + currentShift) % 26;
        }
        return s;
    }
};
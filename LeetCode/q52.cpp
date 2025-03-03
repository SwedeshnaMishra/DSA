//2661. First Completely Painted Row or Column

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, pair<int, int>> cellPosition;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cellPosition[mat[i][j]] = {i, j};
            }
        }

        vector<int> rowPaintCount(m, 0);
        vector<int> colPaintCount(n, 0);

        for (int i = 0; i < arr.size(); ++i) {
            auto [r, c] = cellPosition[arr[i]];
            ++rowPaintCount[r];
            ++colPaintCount[c];

            if (rowPaintCount[r] == n || colPaintCount[c] == m) {
                return i;
            }
        }
        return -1;
    }
};
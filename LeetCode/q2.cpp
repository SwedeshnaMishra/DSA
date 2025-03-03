//3152. Special Array II

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0);

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if ((nums[i - 1] % 2 == nums[i] % 2)) { 
                prefix[i]++;
            }
        }

        vector<bool> result;
        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];

            int count = prefix[end] - (start > 0 ? prefix[start] : 0);

            result.push_back(count == 0);
        }

        return result;
    }
};
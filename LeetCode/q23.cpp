//2471. Minimum Number of Operations to Sort a Binary Tree by Level

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int totalSwaps = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelValues;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            totalSwaps += countMinSwaps(levelValues);
        }
        return totalSwaps;
    }

private:
    int countMinSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> indexedArray(n);

        for (int i = 0; i < n; ++i) {
            indexedArray[i] = {arr[i], i};
        }

        sort(indexedArray.begin(), indexedArray.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            if (visited[i] || indexedArray[i].second == i) continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = indexedArray[j].second;
                ++cycleSize;
            }
            if (cycleSize > 1) {
                swaps += (cycleSize - 1);
            }
        }
        return swaps;
    }
};
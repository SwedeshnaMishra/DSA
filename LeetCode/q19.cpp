//2415. Reverse Odd Levels of Binary Tree

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;

        queue<TreeNode*> q;
        q.push(root);
        bool isOddLevel = false;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> levelNodes;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                levelNodes.push_back(node);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

            }

            if (isOddLevel) {
                int left = 0, right = levelNodes.size() - 1;
                while (left < right) {
                    swap(levelNodes[left]->val, levelNodes[right]->val);
                    left++;
                    right--;
                }
            }
            isOddLevel = !isOddLevel;
        }
        return root;
    }
};
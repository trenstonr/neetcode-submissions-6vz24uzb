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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> res;
        deque<TreeNode*> q; // node, level
        q.push_back(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> levelx;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop_front();
                
                levelx.push_back(node->val);

                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }

            res.push_back(levelx);
        }

        return res;

        // O(n), O(n)
    }
};

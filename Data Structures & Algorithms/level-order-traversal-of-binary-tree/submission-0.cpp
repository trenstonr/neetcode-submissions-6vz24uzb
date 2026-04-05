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
        deque<pair<TreeNode*, int>> q; // node, level
        q.push_back({root, 0});

        while (!q.empty()) {
            auto [node, level] = q.front();
            q.pop_front();
            
            if (res.size() >= level + 1) res[level].push_back(node->val);
            else res.push_back({node->val});

            if (node->left) q.push_back({node->left, level + 1});
            if (node->right) q.push_back({node->right, level + 1});
        }

        return res;

        // O(n), O(n)
    }
};

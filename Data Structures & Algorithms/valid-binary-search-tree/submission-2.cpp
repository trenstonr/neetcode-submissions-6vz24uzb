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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return dfs(root, INT_MIN, INT_MAX);
    }
private:
    bool dfs(TreeNode* node, int mn, int mx) {
        if (!node) return true;

        if (node->val <= mn || node->val >= mx) return false;

        return dfs(node->left, mn, min(node->val, mx))
            && dfs(node->right, max(node->val, mn), mx);
    }
};

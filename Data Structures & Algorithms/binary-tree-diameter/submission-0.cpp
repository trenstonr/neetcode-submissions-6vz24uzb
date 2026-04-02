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
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int l = dfs(root->left);
        int r = dfs(root->right);

        return max(l + r, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
private:
    int dfs(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(dfs(node->left), dfs(node->right));
    }
};

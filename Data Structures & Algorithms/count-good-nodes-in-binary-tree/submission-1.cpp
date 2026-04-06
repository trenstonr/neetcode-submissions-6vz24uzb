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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, root->val, res);
        return res;
    }
private:
    void dfs(TreeNode* node, int currMax, int& res) {
        if (node->val >= currMax) res++;

        currMax = max(node->val, currMax);

        if (node->left) dfs(node->left, currMax, res);
        if (node->right) dfs(node->right, currMax, res);
    }
};

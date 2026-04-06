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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int res;
        dfs(root, count, k, res);
        return res;
    }
private:
    void dfs(TreeNode* node, int& count, int k, int& res) {
        if (!node) return;
        if (count == k) return;

        dfs(node->left, count, k, res);

        if (count == k) return;

        if (++count == k) {
            res = node->val;
            return;
        }

        dfs(node->right, count, k, res);
    }
};

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
        int res = 0;
        vector<int> path;
        dfs(root, path, res);
        return res;
    }
private:
    void dfs(TreeNode* node, vector<int>& path, int& res) {
        if (!node) return;

        if (path.empty()) res++;
        else if (node->val >= *max_element(path.begin(), path.end())) res++;

        path.push_back(node->val);
        dfs(node->left, path, res);
        dfs(node->right, path, res);
        path.pop_back();
    }
};

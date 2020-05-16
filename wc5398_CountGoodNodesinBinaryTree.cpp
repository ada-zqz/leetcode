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
        dfs(root, root->val, res);
        return res;
    }
    void dfs(TreeNode* root, int pre, int& res) {
        if(!root) return;
        if(root->val >= pre) {
            res++;
            pre = root->val;
            dfs(root->left, pre, res);
            dfs(root->right, pre, res);
        }
        else {
            dfs(root->left, pre, res);
            dfs(root->right, pre, res);
        }
    }
};

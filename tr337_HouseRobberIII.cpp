/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        
        int val = 0;
        if(root->left)
            val += rob(root->left->left) + rob(root->left->right);
        if(root->right)
            val += rob(root->right->left) + rob(root->right->right);
        return max(root->val + val, rob(root->left) + rob(root->right));

    }
};

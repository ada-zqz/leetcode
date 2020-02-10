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
    int nsum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root->right) bstToGst(root->right);
        root->val += nsum;
        nsum = root->val;
        if(root->left) bstToGst(root->left);
        return root;
    }
};

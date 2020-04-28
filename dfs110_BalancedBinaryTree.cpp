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
    bool isBalanced(TreeNode* root) {
        return isok(root);
    }
    bool isok(TreeNode* root) {
        if(!root) return true;
        if(isok(root->left) && isok(root->right) && abs(height(root->left) - height(root->right)) <= 1) return true;
        return false;
    }
    int height(TreeNode* root) {
        if(!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
};

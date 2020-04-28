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
        bool isok = true;
        height(root, isok);
        return isok;
    }
    int height(TreeNode* root, bool& isok) {
        if(!isok) return -1;
        // isok = true
        if(!root) return 0;
        int left = height(root->left, isok);
        int right = height(root->right, isok);
        if(abs(left - right) > 1) isok = false;
        return max(left, right) + 1;
    }
};

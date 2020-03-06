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
    int res;
    bool find = false;
    int kthLargest(TreeNode* root, int k) {
        inorder(root, k);
        return res;
    }
    void inorder(TreeNode* root, int& k) {
        if(!find) {
            if(!root) {
                return;
            }
            inorder(root->right, k);
            if(k-- == 1) {
                res = root->val;
                find = true;
                return;
            }
            else {
                inorder(root->left, k);
            }
        }
        
    }
};

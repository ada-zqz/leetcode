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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inorder(root, k, ans);
        return ans;
    }
    bool inorder(TreeNode* & root, int & k, int & ans) {
        if(!root) return false;
        
        if(!inorder(root->left, k, ans)) {
            //left里没找到
            if(k-- == 1) {
                ans = root->val;
                return true;
            } 
            inorder(root->right, k, ans);
        }
        return false;
    }
};

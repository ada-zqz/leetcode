/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef long long ll;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // return sub(root, INT_MIN, INT_MAX); //[2147483647]就判false了
        return sub(root, NULL, NULL); 
    }
    bool sub(TreeNode* root, TreeNode* tmin, TreeNode* tmax) {
        if(!root) return true;
        if((tmax != NULL && root->val >= tmax->val) || (tmin != NULL && root->val <= tmin->val)) return false;
        return sub(root->left, tmin, root) && sub(root->right, root, tmax);
    }
};

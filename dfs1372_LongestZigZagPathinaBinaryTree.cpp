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
    int ans = 0;
    int longestZigZag(TreeNode* root) {
        int leftp = 1 + sub(root->left, 1);
        int rightp = 1 + sub(root->right, 0);
        int nmax = max(leftp, rightp);
        if(nmax > ans) ans = nmax;
        return ans;
    }
    int sub(TreeNode* root, int left) {
        if(!root) return -1;
        if(!root->left && !root->right) return 0;
        int subp_l = 1 + sub(root->left, 1); //left == 0
        int subp_r = 1 + sub(root->right, 0);    
        int nmax = max(subp_l, subp_r);
        if(nmax > ans) ans = nmax;
        return left ? subp_r : subp_l;
    }
};

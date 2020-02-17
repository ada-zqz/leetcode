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
    int maxDepth(TreeNode* root) {
        int dp = 0;
        dp = maxDsub(dp, root);
        return dp;
    }
    int maxDsub(int dp, TreeNode* root) {
        if(root == NULL) return dp;
        return max(maxDsub(dp + 1, root->left), maxDsub(dp + 1, root->right));
    }
};

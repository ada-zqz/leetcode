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
    TreeNode* bstToGst(TreeNode* root) {
        int nsum = 0;
        NodeSum(root, nsum);
        return root;
    }
    void NodeSum(TreeNode* now, int& nsum) {
        if(!now) return;
        NodeSum(now->right, nsum);
        now->val += nsum;
        nsum = now->val;
        NodeSum(now->left, nsum);
    }
};

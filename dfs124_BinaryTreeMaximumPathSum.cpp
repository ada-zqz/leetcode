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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        childmax(root, res);
        return res;
    }
    int childmax(TreeNode* root, int& res) {
        if(!root) return 0;
        int leftmax = childmax(root->left, res);
        int rightmax = childmax(root->right, res);
        res = max(res, max(0, leftmax) + max(0, rightmax) + root->val);
        return max(root->val, max(leftmax, rightmax) + root->val);
    }
};

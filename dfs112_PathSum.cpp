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
    bool hasPathSum(TreeNode* root, int sum) {
        return pathsub(root, sum);
    }
    bool pathsub(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right) { //叶结点
            if(root->val == sum) return true;
            else return false;
        }
        sum = sum - root->val;
        return pathsub(root->left, sum) || pathsub(root->right, sum);
    }
};

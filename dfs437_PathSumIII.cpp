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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return pathsub(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int pathsub(TreeNode* root, int sum) {
        if(!root) return 0;
        return int(root->val == sum) + pathsub(root->left, sum - root->val) + pathsub(root->right, sum - root->val); //包括root->val
    }
};

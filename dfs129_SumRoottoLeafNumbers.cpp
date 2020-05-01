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
    int sumNumbers(TreeNode* root) {
        int sm = 0;
        number(root, 0, sm);
        return sm;
    }
    void number(TreeNode* root, int pre, int & sm) {
        if(!root) {
            return;
        }
        int now = 10 * pre + root->val;
        if(!root->left && !root->right) {
            // 叶子结点
            sm += now;
            return;
        }
        number(root->left, now, sm);
        number(root->right, now, sm);
    }
};

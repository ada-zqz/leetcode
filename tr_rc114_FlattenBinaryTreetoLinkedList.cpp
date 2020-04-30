/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* pre = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        // 怎么把左右flatten后的接起来？  多设一个指针，指向变为list的树的root
        flatten(root->right);  // 变成右子树一链
        flatten(root->left);   // 右子树flatten好了以后，要接到左子树，左子树再变为右子树
        root->right = pre;
        root->left = NULL;
        // root已经排好
        pre = root;
    }
};

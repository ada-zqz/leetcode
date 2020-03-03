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
    int longest = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return longest;
    }
    int dfs(TreeNode* root) {
        if(root == NULL) return -1;
        if(root->left == NULL && root->right == NULL) return 0;
        int leftpath = 1 + dfs(root->left);
        int rightpath = 1 + dfs(root->right);
        if(leftpath + rightpath > longest) longest = leftpath + rightpath;
        return max(leftpath, rightpath);  //内部节点到叶节点的最长的路径长度
    }
};

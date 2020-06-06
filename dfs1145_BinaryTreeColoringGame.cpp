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
    TreeNode* findNode(TreeNode* root, int& x) {
        // x所在的节点
        if(!root) return NULL;
        if(root->val == x) return root;
        TreeNode* temp = findNode(root->left, x);
        if(!temp) temp = findNode(root->right, x);
        return temp;
    }
    void countNode(TreeNode* root, int& m) {
        if(root) {
            m++;
            countNode(root->left, m);
            countNode(root->right, m);
        }
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* red = findNode(root, x);
        int left = 0, right = 0, blue;
        // red左右孩子的个数
        countNode(red->left, left);
        countNode(red->right, right);
        // blue在red的左右孩子或者父节点中选择
        blue = max(left, right);
        blue = max(blue, n - 1 - left - right);
        return blue > (n - blue);
    }
};

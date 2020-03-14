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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int ni = inorder.size();
        int np = postorder.size();
        return subtree(inorder, 0, ni - 1, postorder, 0, np - 1);
    }
    TreeNode* subtree(vector<int>& inorder, int il, int ir, vector<int>& postorder, int pl, int pr) {
        if(ir < il) return nullptr;
        int val = postorder[pr];
        TreeNode* root = new TreeNode(val);
        if(ir == il) return root;
        
        int nleft; //左子树的个数
        int pos;   //根的位置
        for(int i = il; i <= ir; i++) {
            if(inorder[i] == val) {
                nleft = i - il;
                pos = i;
                break;
            }
        }
        root->left = subtree(inorder, il, pos - 1, postorder, pl, pl + nleft - 1);
        root->right = subtree(inorder, pos + 1, ir, postorder, pl + nleft, pr - 1);
        return root;
    }
};

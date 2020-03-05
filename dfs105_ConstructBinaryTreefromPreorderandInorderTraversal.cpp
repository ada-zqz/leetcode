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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildsub(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* buildsub(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        //前序遍历第一个是根节点，然后遍历左子树，右子树
        //中序遍历根节点左边是左子树，右边是右子树
        if(pr < pl || pr < 0) return NULL;
        TreeNode* root = new TreeNode(preorder[pl]);
        if(pr == pl) return root;
        int len;
        for(int i = il; i <= ir; i++) {
            //找到root在中序遍历的位置
            if(inorder[i] == root->val) {
                len = i - il;
                break;
            }
        }
        root->left = buildsub(preorder, inorder, pl + 1, pl + len, il, il + len - 1);
        root->right = buildsub(preorder, inorder, pl + len + 1, pr, il + len + 1, ir);
        return root;
    }
};

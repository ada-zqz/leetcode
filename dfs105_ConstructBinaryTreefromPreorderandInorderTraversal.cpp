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
        //前序遍历第一个是根节点，然后遍历左子树，右子树
        //中序遍历根节点左边是左子树，右边是右子树
        if(preorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1) return root;
        vector<int> inorder_l, inorder_r; //分别存放左右子树的节点
        vector<int> preorder_l, preorder_r; //分别存放左右子树的节点
        bool rcd_l = true;
        for(int i = 0; i < inorder.size(); i++) {
            //找到root在中序遍历的位置
            if(inorder[i] == root->val) {
                rcd_l = false;
                continue;
            }
            if(rcd_l) {
                inorder_l.push_back(inorder[i]);
                preorder_l.push_back(preorder[i + 1]);
            }
            else {
                inorder_r.push_back(inorder[i]);
                preorder_r.push_back(preorder[i]);
            }
        }
        root->left = buildTree(preorder_l, inorder_l);
        root->right = buildTree(preorder_r, inorder_r);
        return root;
    }
};

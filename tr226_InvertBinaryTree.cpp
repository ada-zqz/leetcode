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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        queue<TreeNode*> layer;
        layer.push(root);
        while(!layer.empty()) {
            TreeNode* p;
            p = layer.front();
            layer.pop();
            swap(p->left, p->right);
            if(p->left) layer.push(p->left);
            if(p->right) layer.push(p->right);
        }
        return root;        
    }
};

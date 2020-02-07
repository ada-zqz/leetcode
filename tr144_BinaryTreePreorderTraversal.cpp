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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) 
            return res;
        
        stack<TreeNode*> tree;
        TreeNode* p = root;
        tree.push(NULL);
        while(p) {
            cout << p->val << endl;
            res.push_back(p->val);
            if(p->right) {
                tree.push(p->right);
            }
            if(p->left) {
                p = p->left;
            }
            else {
                p = tree.top();
                tree.pop();
            }
        }
        return res;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//先左，再中，最后右
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        stack<TreeNode*> tree;
        TreeNode* p = root;
        while(p || !tree.empty()) {
            if(p) {
                tree.push(p);
                p = p->left;
            }
            else {
                p = tree.top();
                tree.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};

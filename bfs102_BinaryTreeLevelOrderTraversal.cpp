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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root) return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            queue<TreeNode*> qn;
            vector<int> vt;
            while(!q.empty()) {
                TreeNode* t = q.front();
                q.pop();
                vt.push_back(t->val);
                if(t->left) qn.push(t->left);
                if(t->right) qn.push(t->right);
            }
            v.push_back(vt);
            q = qn;
        }
        return v;
    }
};

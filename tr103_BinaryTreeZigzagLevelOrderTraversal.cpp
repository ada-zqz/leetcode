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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        stack<TreeNode*> ptr;
        ptr.push(root);
        int n = 1;
        while(!ptr.empty()) {
            vector<int> zig;
            stack<TreeNode*> newptr;
            TreeNode* p;
            while(!ptr.empty()) {
                p = ptr.top();
                ptr.pop();
                zig.push_back(p->val);
                if(n % 2) {
                    if(p->left) newptr.push(p->left);
                    if(p->right) newptr.push(p->right);
                }
                else {
                    if(p->right) newptr.push(p->right);
                    if(p->left) newptr.push(p->left);
                }
            }
            n += 1;
            res.push_back(zig);
            ptr = newptr;
        }
        return res;
    }
};

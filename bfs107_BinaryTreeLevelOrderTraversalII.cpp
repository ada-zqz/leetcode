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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        set<TreeNode*> q;
        q.insert(root);
        while(!q.empty()) {
            set<TreeNode*> pq;
            vector<int> v;
            for(auto p: q) {
                if(p) {
                    v.push_back(p->val);
                    pq.insert(p->left);
                    pq.insert(p->right);
                }
            }
            if(v.size() > 0) res.push_back(v);
            swap(q, pq);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

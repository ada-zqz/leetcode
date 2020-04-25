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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        set<TreeNode*> q;
        q.insert(root);
        while(!q.empty()) {
            set<TreeNode*> pq;
            double v = 0;
            int n = 0;
            for(auto p: q) {
                if(p) {
                    n++;
                    v += p->val;
                    pq.insert(p->left);
                    pq.insert(p->right);
                }
            }
            if(n > 0) {
                v /= n;
                res.push_back(v);
            }
            swap(q, pq);
        }
        return res;
    }
};

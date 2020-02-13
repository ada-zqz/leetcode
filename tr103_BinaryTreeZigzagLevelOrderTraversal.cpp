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
        
        queue<TreeNode*> pq;
        pq.push(root);
        bool ltor = true;
        while(!pq.empty()) {
            int nsize = pq.size();
            vector<int> zig(nsize);
            for(int i = 0; i < nsize; i++) {
                TreeNode* p = pq.front();
                pq.pop();
                
                int index = ltor ? i : (nsize - 1 - i); 
                zig[index] = p->val;
                if(p->left) pq.push(p->left);
                if(p->right) pq.push(p->right);
            }
            ltor = !ltor;
            res.push_back(zig);
        }
        return res;
    }
};

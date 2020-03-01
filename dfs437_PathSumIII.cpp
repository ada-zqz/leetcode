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
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        vector<int> prev;
        int res = 0;
        dfs(root, prev, sum, res);
        return res;
    }
    void dfs(TreeNode* root, vector<int> prev, int sum, int& res) {
        if(!root) return;
        vector<int> v;
        v.push_back(root->val);
        if(root->val == sum) res++;
        for(int pre: prev) {
            int vnew = root->val + pre;
            v.push_back(vnew);
            if(vnew == sum) res++;
        }
        dfs(root->left, v, sum, res);
        dfs(root->right, v, sum, res);
    }
};

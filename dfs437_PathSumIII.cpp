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
        for(int i = 0; i < prev.size(); i++) {
            prev[i] += root->val;
            if(prev[i] == sum) res++;
        }
        prev.push_back(root->val);
        if(root->val == sum) res++;
        dfs(root->left, prev, sum, res);
        dfs(root->right, prev, sum, res);
    }
};

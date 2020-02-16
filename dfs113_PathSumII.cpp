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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> v;
        pathsub(root, sum, v, res);
        return res; 
    }
    void pathsub(TreeNode* root, int sum, vector<int>& v, vector<vector<int>>& res) {
        if(root == NULL) return;
        v.push_back(root->val);
        if(sum == root->val && !root->left && !root->right) {
            // 找到叶子节点
            res.push_back(v);
        }
        pathsub(root->left, sum - root->val, v, res);
        pathsub(root->right, sum - root->val, v, res);
        v.pop_back();
    }
};

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
        if(root == NULL) return res;
        vector<int> v;
        pathsub(root, sum, v, res);
        return res; 
    }
    void pathsub(TreeNode* root, int sum, vector<int>& v, vector<vector<int>>& res) {
        if(sum == root->val && !root->left && !root->right) {
            // 找到叶子节点
            v.push_back(root->val);
            res.push_back(v);
            v.erase(v.end() - 1);
            return;
        }
        if(root->left) {
            v.push_back(root->val);
            pathsub(root->left, sum - root->val, v, res);
            v.erase(v.end() - 1);
        }
        if(root->right) {
            v.push_back(root->val);
            pathsub(root->right, sum - root->val, v, res);
            v.erase(v.end() - 1);
        }
        return;
    }
};

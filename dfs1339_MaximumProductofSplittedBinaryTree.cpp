typedef long long ll;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void countsum(TreeNode* root, ll& sm) {
        // 计算所有节点的和
        if(root) {
            sm += root->val;
            countsum(root->left, sm);
            countsum(root->right, sm);
        }
    }
    ll subsm(TreeNode* root, ll& pd, ll& sm) {
        // 计算左右子树的和，并且判断乘积
        ll sbsm = 0, leftsm = 0, rightsm = 0;
        if(root) {
            sbsm = root->val;
            leftsm = subsm(root->left, pd, sm);
            rightsm = subsm(root->right, pd, sm);
            // // 以为分的子树at least 2 nodes
            // if(root->left && (root->left->val < leftsm)) pd = max(pd, leftsm * (sm - leftsm));
            // if(root->right && (root->right->val < rightsm)) pd = max(pd, rightsm * (sm - rightsm));
            if(root->left) pd = max(pd, leftsm * (sm - leftsm));
            if(root->right) pd = max(pd, rightsm * (sm - rightsm));
        }
        return sbsm + leftsm + rightsm;
        
    }
    int maxProduct(TreeNode* root) {
        ll sm = 0, pd = 0, MOD = 1e9 + 7;
        countsum(root, sm);
        subsm(root, pd, sm);
        return pd % MOD;
    }
};

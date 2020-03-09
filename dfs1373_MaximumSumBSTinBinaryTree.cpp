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
    int ans = 1<<31;
    int maxSumBST(TreeNode* root) {
        BST(root);
        return max(0, ans);
    }
    vector<int> BST(TreeNode* root) {
        if(!root) return vector<int>({2, 0, 1<<31, 1<<30});
        if(!root->left && !root->right) {
            if(ans < root->val) ans = root->val;
            return vector<int>({1, root->val, root->val, root->val});
        }
        vector<int> ltree = BST(root->left);
        vector<int> rtree = BST(root->right);
        vector<int> tree(4); //是否时BST，sum，最大值，最小值
        if(ltree[0] && rtree[0] && root->val > ltree[2] && root->val < rtree[3]) {
            tree[0] = 1;
            tree[1] = ltree[1] + rtree[1] + root->val;
            tree[2] = rtree[0] == 1 ? rtree[2] : root->val;
            tree[3] = ltree[0] == 1 ? ltree[3] : root->val;
            if(ans < tree[1]) ans = tree[1];
            return tree;
        }
        else return vector<int>({0, 0, 0, 0});
    }
};

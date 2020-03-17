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
    void inorder(TreeNode* root, vector<int>& t) {
        if(!root) return;
        inorder(root->left, t);
        t.push_back(root->val);
        inorder(root->right, t);
    }
    TreeNode* buildtree(vector<int>& t, int l, int r) {
        if(l > r) return nullptr;
        if(l == r) {
            TreeNode* tr = new TreeNode(t[l]);
            return tr;
        }
        int mid = (l + r) / 2;
        TreeNode* tr = new TreeNode(t[mid]);
        tr->left = buildtree(t, l, mid - 1);
        tr->right = buildtree(t, mid + 1, r);
        return tr;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> t;
        // 先排序
        inorder(root, t);
        // 重新构建树
        int n = t.size();
        root = buildtree(t, 0, n - 1);
        return root;
    }
};

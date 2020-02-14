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
    int rob(TreeNode* root) {
        map<TreeNode*, int> robmap;
        return subrob(root, robmap);
    }
    
    int subrob(TreeNode* root, map<TreeNode*, int> & robmap) {
        if(root == NULL) return 0;
        if(robmap.find(root) != robmap.end()) return robmap.find(root)->second;
        
        int val = 0;
        if(root->left)
            val += subrob(root->left->left, robmap) + subrob(root->left->right, robmap);
        if(root->right)
            val += subrob(root->right->left, robmap) + subrob(root->right->right, robmap);
        val = max(root->val + val, subrob(root->left, robmap) + subrob(root->right, robmap));
        
        robmap.insert(pair<TreeNode*, int>(root, val));
        return val;
    }
};

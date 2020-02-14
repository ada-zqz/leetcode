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
        vector<int> res(2); 
        res = subrob(root); 
        return max(res[0], res[1]);
    }
    vector<int> subrob(TreeNode* root) {
        vector<int> val(2, 0);
        if(root == NULL) return val;
        
        vector<int> left = subrob(root->left); 
        vector<int> right = subrob(root->right); 
        //valwithoutrootincluded val[0]; valwithrootincluded val[1]
        val[1] = root->val + left[0] + right[0];
        val[0] = max(left[0], left[1]) + max(right[0], right[1]);
        return val;
    }
};

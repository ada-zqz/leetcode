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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        vector<TreeNode*> v;
        v.push_back(root->left);
        v.push_back(root->right);
        while(!v.empty()) {
            int s = v.size();
            vector<TreeNode*> vnew;
            vector<bool> add(s, false);
            for(int i = 0; i < s/2; i++) {
                if(v[i] == NULL && v[s - i - 1] == NULL) continue;
                if((v[i] == NULL && v[s - i - 1] != NULL) || (v[i] != NULL && v[s - i - 1] == NULL)) return false;
                if(v[i]->val != v[s - i - 1]->val) return false;
                add[i] = true;
                add[s - i -1] =true;
            }
            for(int i = 0; i < s; i++) {
                if(add[i]) {
                    vnew.push_back(v[i]->left);
                    vnew.push_back(v[i]->right);
                }
            }
            v = vnew;
        }
        return true;
    }
};

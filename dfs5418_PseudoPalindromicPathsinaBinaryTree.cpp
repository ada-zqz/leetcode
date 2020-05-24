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
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;
        vector<int> pd;
        dfs(root, pd, res);
        return res;
    }
    void dfs(TreeNode* root, vector<int>& pd, int& res) {
        if(!root) return;
        if(!root->left && !root->right) {
            //叶子节点
            pd.push_back(root->val);
            if(ispd(pd)) res++;
            pd.pop_back();
        }
        else {
            pd.push_back(root->val);
            dfs(root->left, pd, res);
            dfs(root->right, pd, res);
            pd.pop_back();
        }
    }
    bool ispd(vector<int> pd) {
        // for(auto p: pd) cout << p << " ";
        // cout << endl;
        unordered_set<int> st;
        for(auto p: pd) {
            if(st.find(p) == st.end()) st.insert(p);
            else st.erase(p);
        }
        if(st.size() <= 1) return true;
        else return false;
    }
};

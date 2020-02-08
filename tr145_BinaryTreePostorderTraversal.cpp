/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct pNode {
    TreeNode* p;
    int tag = -1;    //标志从哪回来 0 Left; 1 Right
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        
        TreeNode* pt = root;
        pNode pn;
        stack<pNode> tree;
        while(pt || !tree.empty()) {
            while(pt) {
                pn.p = pt;
                pn.tag = 0;  
                tree.push(pn);
                pt = pt->left;
            }
            pn = tree.top();
            tree.pop();
            pt = pn.p;
            if(pn.tag == 0) {
                pn.tag = 1;
                tree.push(pn);
                pt = pt->right;
            }
            else {
                res.push_back(pt->val);
                pt = NULL;
            }
        }
        return res;
    }
};

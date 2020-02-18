/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct couple {
    TreeNode *o;
    TreeNode *t;
    couple(TreeNode* one, TreeNode* two): o(one), t(two) {}
};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<couple> st;
        st.push(couple(p, q));
        while(!st.empty()) {
            couple c = st.top();
            st.pop();
            if(((c.o != NULL) && (c.t == NULL)) || ((c.o == NULL) && (c.t != NULL))) return false;
            if((c.o != NULL) && (c.t != NULL)) {
                if(c.o->val != c.t->val) return false;
                st.push(couple(c.o->left, c.t->left));
                st.push(couple(c.o->right, c.t->right));
            }
        }
        return true;
    }
};

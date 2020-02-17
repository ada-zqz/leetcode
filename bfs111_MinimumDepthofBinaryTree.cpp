/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct node {
    int h;
    TreeNode* p;
    node(int hn, TreeNode* pn): h(hn), p(pn) {}
};
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<node> bfs;
        bfs.push(node(1, root));
        while(!bfs.empty()) {
            node nown = bfs.front();
            bfs.pop();
            if(!nown.p->left && !nown.p->right) return nown.h; //左右孩子为空，不用压到队列了
            if(nown.p->left != NULL) bfs.push(node(nown.h + 1, nown.p->left));
            if(nown.p->right != NULL) bfs.push(node(nown.h + 1, nown.p->right));
        }
        return -1;
    }
};

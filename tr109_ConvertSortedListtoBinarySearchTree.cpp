/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode* now;
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;    // 节点数
        now = head;
        while(now) {
            now = now->next;
            n++;
        }
        now = head;   // 从头开始构造 
        return buildtree(n);
    }
    TreeNode* buildtree(int n) {
        if(n == 0) return NULL;
        TreeNode* left = buildtree(n / 2);  // 从头开始n/2个构造好左子树
        TreeNode* root = new TreeNode(now->val);
        now = now->next;
        root->left = left;
        root->right = buildtree(n - n / 2 - 1);
        return root;
    }
};

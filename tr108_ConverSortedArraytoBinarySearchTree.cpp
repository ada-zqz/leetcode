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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return NULL;
        return buildroot(nums, 0, (n - 1) / 2, n - 1);
    }
    TreeNode* buildroot(vector<int>& nums, int left, int mid, int right) {
        TreeNode* root = new TreeNode(nums[mid]);
        if(left < mid) {
            root->left = buildroot(nums, left, (left + mid - 1) / 2, mid - 1);
            root->right = buildroot(nums, mid + 1, (mid + 1 + right) / 2, right);
        }
        else if(right > mid) {
            // left == mid && right > mid
            root->right = buildroot(nums, mid + 1, (mid + 1 + right) / 2, right);
        }
        return root;
    }
};

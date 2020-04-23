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
    // 总时间st, 可并行时间pt，实际执行时间st - pt
    // 左子树总时间a，可并行时间b；右子树总时间c，可并行时间d
    // a>c: 左右子树可并行c，剩下左子树a-c的任务量
    // 若a-c<=2b，a-c的任务量可并行，总时间a+c+root.val，总并行时间(2c+a-c)/2=(a+c)/2
    // 若a-c>2b，2b的任务量可并行，其余a-c-2b需要串行，总时间a+c+root.val，总并行时间(2c+2b)/2=b+c
    pair<double, double> dfs(TreeNode* root) {
        if(!root) return {0, 0};
        auto rt = root->val;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if(left.first < right.first) {
            swap(left, right);
        }
        if(left.first - right.first <= 2 * left.second) {
            return {left.first + right.first + rt, 0.5 * (left.first + right.first)};
        }
        else {
            return {left.first + right.first + rt, left.second + right.first};
        }
    }
    double minimalExecTime(TreeNode* root) {
        auto res = dfs(root);
        return res.first - res.second;
    }

};

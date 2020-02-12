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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n == 0) return res;
        return generateTree(1, n);
    }
    vector<TreeNode*> generateTree(int start, int end) {
        vector<TreeNode *> res;
        if(start > end) {
            // res.push_back(0), 会返回[[]]; 只有定义不push_back，返回[]
            res.push_back(nullptr);
        }
        if(start == end) {
            res.push_back(new TreeNode(start));
        }
        if(start < end) {
            for(int nowroot = start; nowroot <= end; nowroot++) {
                vector<TreeNode*> left = generateTree(start, nowroot - 1);
                vector<TreeNode*> right = generateTree(nowroot + 1, end);
                
                for(int j = 0; j < left.size(); j++) {
                    for(int k = 0; k < right.size(); k++) {
                        TreeNode* newroot = new TreeNode(nowroot);
                        newroot->left = left[j];
                        newroot->right = right[k];
                        res.push_back(newroot);
                    }
                }
            }
        }
        return res;
    }
};

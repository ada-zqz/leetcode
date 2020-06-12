/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k, NULL);
        if(!root) return res;
        int n = 0;
        auto tmp = root;
        while(tmp) {
            n++;
            tmp = tmp->next;
        }
        int m = n / k, t = n % k;
        tmp = root;
        auto pre = tmp;
        for(int i = 0; i < k; i++) {
            if(!tmp) break;  //已经划分完成
            res[i] = tmp;
            int l = m;
            while(l-- > 0) {
                pre = tmp;
                tmp = tmp->next;
            }
            if(i < t)  {
                // 多一个
                pre = tmp;
                tmp = tmp->next;
            }
            pre->next = NULL;
        }
        return res;
    }
};

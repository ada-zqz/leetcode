/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        while(head != NULL) {
            ans.push_back(head->val);
            head = head->next;
        }
        int len = ans.size();
        vector<int> res(len);
        for(int i = 0; i < len; i++) res[len - i - 1] = ans[i];
        return res;
    }
};

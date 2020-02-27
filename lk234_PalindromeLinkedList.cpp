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
    bool isPalindrome(ListNode* head) {
        vector<int> lk;
        while(head) {
            lk.push_back(head->val);
            head = head->next;
        }
        int len = lk.size();
        for(int i = 0; i < len / 2; i++) {
            if(lk[i] != lk[len - i -1]) return false;
        }
        return true;
    }
};

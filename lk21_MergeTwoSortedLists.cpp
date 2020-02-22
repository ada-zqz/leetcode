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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode lnew(0);
        lnew.next = NULL;
        
        ListNode* ltmp = &lnew;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                ltmp->next = l1;
                l1 = l1->next;
            }
            else {
                ltmp->next = l2;
                l2 = l2->next;
            }
            ltmp = ltmp->next;
        }
        ltmp->next = l1 ? l1 : l2;
        return lnew.next;
    }
};

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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* rev = reverseList(head->next); //head后已经调整好
        head->next->next = head;  //定位rev最后一个非空指针
        head->next = NULL;
        return rev;
    }
};

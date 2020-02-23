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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        ListNode *a = headA, *b = headB;
        while(a != b) {
            a = a->next;
            b = b->next;
            if(a == b && !a) return nullptr;  //都指向末尾，没找到交点
            if(a == NULL) a = headB;
            if(b == NULL) b = headA;
        }
        return a;
    }
};

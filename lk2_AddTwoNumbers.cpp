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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* pre;
        int n, nn = 0;
        while(l1 && l2) {
            n = l1->val + l2->val + nn;
            nn = n / 10; //进位
            n = n % 10;
            l1->val = n;
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* l3;
        l3 = l2 ? l2 : l1;
        pre->next =l3;
        while(l3) {
            n = l3->val + nn;
            nn = n / 10;
            n = n % 10;
            l3->val = n;
            pre = l3;
            l3 = l3->next;
        }
        if(nn != 0) {
            ListNode* end = new ListNode(nn); //不new的话局部变量会消失
            pre->next = end;
        }
        return head;
    }
};

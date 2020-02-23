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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        int len = 0;
        ListNode* tmp = head;
        while(tmp) {
            len++; tmp = tmp->next;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode *l, *r, *tail;
        for(int d = 1; d < len; d<<=1) {
            tail = &dummy;
            tmp = dummy.next;
            while(tmp) {
                l = tmp;
                r = split(tmp, d);
                tmp = split(r, d);
                auto mg = merge(l, r);
                tail->next = mg.first;
                tail = mg.second;
            }
        }
        return dummy.next;
    }
    
    ListNode* split(ListNode* head, int n) {
        while(--n && head) {
            head = head->next;
        }
        ListNode* tail = head ? head->next : nullptr;
        if(head) head->next = NULL;
        return tail; //返回head后第n个指针
    }
    
    pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode*l2) {
        ListNode dummy(0);
        ListNode* l = &dummy;
        while(l1 && l2) {
            if(l1->val > l2->val) swap(l1, l2);
            l->next = l1;
            l1 = l1->next;
            l = l->next;
        }
        if(l2) l->next = l2;  //如果开始l1,l2不为空，结束一定是l1为空
        if(l1) l->next = l1;  //一开始l2就为空的情况
        while(l->next) l = l->next;
        return {dummy.next, l}; //返回merge后的首尾指针
    }
};

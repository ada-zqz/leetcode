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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        auto odd = head, even = head->next;
        auto pre = head->next->next, tmp = head->next;
        while(pre) {
            odd->next = pre;
            even->next = pre->next;
            odd = odd->next;
            even = even->next;
            if(!pre->next) {
                // pre odd最后一个
                odd->next = tmp;
                break;
            }
            else if(!pre->next->next) {
                // pre->next even最后一个
                even->next = NULL;
                odd->next = tmp;
                break;
            }
            else 
                pre = pre->next->next;
        }
        return head;
    }
};

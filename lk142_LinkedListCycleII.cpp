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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool cyc = false;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                cyc = true; 
                break;
            }
        }
        if(cyc) {
            int ncyc = 1;
            slow = slow->next;
            fast = fast->next->next;
            while(slow != fast) {
                ncyc += 1;
                slow = slow->next;
                fast = fast->next->next;
            }
            slow = head;
            for(int i = 0; i < ncyc; i++) fast = fast->next;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
        return NULL;
    }
};

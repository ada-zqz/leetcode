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
        ListNode *slow = head, *fast = head, *pre = nullptr, *tmp;
        while(fast && fast->next) {
            // find middle position
            fast = fast->next->next;
            // reverse slow
            tmp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = tmp;
        }
        fast = !fast ? slow : slow->next;
        slow = pre;
        while(slow) {
            if(slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};

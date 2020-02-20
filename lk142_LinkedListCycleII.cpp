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
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                // s2 - s1 = nL，s2/s1是快/慢走的距离，L是环的长度，n是倍数
                // s2 = 2s1 -> s1 = nL，s1的位置已经是环的整数倍
                // 一个从头节点开始，一个从head+nL开始，遇到环的起点是会重合
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int n = 0;
        auto tmp = head;
        auto end = head;
        while(tmp) {
            // list的长度，最后不为NULL的节点的位置end
            n++;
            end = tmp;
            tmp = tmp->next;
        }
        k = k % n;
        if(k == 0) return head;
        end->next = head; // 连成一个环
        tmp = head;
        n = n - k;
        while(--n) {
            // 找到开环的位置
            tmp = tmp->next;
        }
        end = tmp->next;
        tmp->next = NULL; //把环打开
        return end;
    }
};

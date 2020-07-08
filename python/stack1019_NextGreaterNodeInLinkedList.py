# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        res, stack = [], [] # stack: val, index
        while head:
            while stack and stack[-1][0] < head.val:
                res[stack.pop()[1]] = head.val
            stack.append([head.val, len(res)])
            res.append(0)
            head = head.next
        return res

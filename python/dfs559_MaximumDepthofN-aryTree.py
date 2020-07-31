"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if root == None:
            return 0
        dp = 0
        for child in root.children:
            dp = max(dp, self.maxDepth(child))
        return dp + 1 

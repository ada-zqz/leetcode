class Solution:
    def findLHS(self, nums: List[int]) -> int:
        # count = collections.Counter(nums)
        count = {}
        for x in nums:
            count[x] = count.get(x, 0) + 1
        ans = 0
        for x in count:
            if x+1 in count:
                ans = max(ans, count[x] + count[x+1])
        return ans

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        sn = sorted(nums)
        return [sn.index(a) for a in nums]

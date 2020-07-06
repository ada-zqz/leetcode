class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        sn = sorted(nums)
        return map(sn.index, nums)

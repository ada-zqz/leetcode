class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        # Boyer-Moore Majority Vote algorithm
        cnt1, cnt2, tmp1, tmp2 = 0, 0, 0, 1
        for n in nums:
            if n == tmp1:
                cnt1 += 1
            elif n == tmp2:
                cnt2 += 1
            elif cnt1 == 0:
                cnt1, tmp1 = 1, n
            elif cnt2 == 0:
                cnt2, tmp2 = 1, n
            else:
                cnt1 -= 1
                cnt2 -= 1
        return [n for n in (tmp1, tmp2) if nums.count(n) > len(nums) / 3]
            

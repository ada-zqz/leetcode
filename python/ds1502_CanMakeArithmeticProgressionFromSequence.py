class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        vmin = min(arr)
        step = (max(arr) - vmin) / (len(arr) - 1)
        if step == 0: return True
        diff = set(nm - vmin for nm in arr)
        return len(diff) == len(arr) and all(d % step == 0 for d in diff)

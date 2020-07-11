class Solution:
    def nextGreaterElement(self, n: int) -> int:
        # 12 -> [1, 2]
        s = list(map(int, str(n))) 
        i = len(s) - 1
        # 从后向前是递增的，3，2，1
        while i - 1 >= 0 and s[i - 1] >= s[i]:  
            i -= 1
        
        # 已经是最大值
        if i == 0: return -1
    
        # s[j - 1] < s[j] > s[j + 1]
        j = i
        # s[j] > s[i - 1], 找到从j+1开始向后的最小的大于s[i-1]的值（已经是递减的顺序了）
        while j + 1 < len(s) and s[j + 1] > s[i - 1]:
            j += 1
        s[i - 1], s[j] = s[j], s[i - 1]  # 3, 5, 4, 1  -> 4, 5(i), 3(j), 1
        
        s[i:] = reversed(s[i:])
        res = int(''.join(map(str, s)))
        
        return res if res <= ((1 << 31) -1) else -1

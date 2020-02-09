import numpy as np

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = np.zeros((len(text1) + 1, len(text2) + 1))
        for n1, c1 in enumerate(text1):
            for n2, c2 in enumerate(text2):
                if c1 == c2:
                    dp[n1 + 1, n2 + 1] = dp[n1, n2] + 1
                else:
                    dp[n1 + 1, n2 + 1] = max(dp[n1, n2 + 1], dp[n1 + 1, n2])
        return int(dp[n1 + 1, n2 + 1])

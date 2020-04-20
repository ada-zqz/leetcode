class Solution(object):
    def findMinFibonacciNumbers(self, k):
        fib = [1,1]
        ans = 0
        while fib[-1] < k:
            fib.append(fib[-1] + fib[-2])
        while fib and k:
            x = fib.pop()
            if k >= x:
                k -= x
                ans += 1
        return ans

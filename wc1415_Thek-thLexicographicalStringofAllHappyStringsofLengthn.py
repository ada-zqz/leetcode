class Solution(object):
    def getHappyString(self, n, k):
        path = []; ans = []
        def search(i):
            if i == n:
                ans.append(path[:])
                return
            for d in range(3):
                if not path or path[-1] != d:
                    path.append(d)
                    search(i + 1)
                    path.pop()
        search(0)
        if k > len(ans): return ""
        k -= 1;
        bns = ans[k]
        return "".join('abc'[d] for d in bns)  # 也可以建立path时就转换好

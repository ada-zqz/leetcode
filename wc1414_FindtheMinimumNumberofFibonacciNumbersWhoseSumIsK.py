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

# class Solution {
# public:
#     int findMinFibonacciNumbers(int k) {
#         vector<int> fib;
#         fib.push_back(1);
#         fib.push_back(1);
#         while(fib.back() < k){
#             fib.push_back(fib.back() + fib[fib.size() - 2]);
#         }
#         reverse(fib.begin(), fib.end());
#         int ans = 0;
#         for(int v : fib){
#             while(k >= v){
#                 k -= v;
#                 ans++;
#             }
#         }
#         return ans;
#     }
# };

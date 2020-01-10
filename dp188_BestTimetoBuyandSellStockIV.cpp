#define MAX(a, b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n < 2) {
            return 0;
        }
        
        if(k >= n/2) {
            int maxp = 0;
            for(int i = 1; i < n; i++) {
                if(prices[i] > prices[i - 1]) {
                    maxp += prices[i] - prices[i - 1]; //只要比前面大就可以买卖
                    // e.g., 1, 2, 3 (diff 0, 1, 1) 交易一次也对应连续加差值
                }
            }
            return maxp;
        }
        
        vector<int> dp1(n, 0), dp2(n, 0);
        int premax;
        for(int i = 1; i < k + 1; i++) {
            premax = dp1[0] - prices[0];
            for(int j = 1; j < n; j++) {
                // 到j为止，至多i次交易的最大收益 dp[i][j]
                // MAX(到j-1为止，至多i次交易的最大收益dp[i][j-1]， 第j项被交易的最大值)
                // max(prices[j] - prices[l] + dp[i - 1][l]), 0<=l<=j-1
                // (l没被交易，prices相减符合逻辑；l被交易了，再交易j相当于l没被交易，符合收益最大)
                // prices[j] - max(dp[i-1][l] - prices[l])
                dp2[j] = MAX(dp2[j - 1], prices[j] + premax);
                premax = MAX(premax, dp1[j] - prices[j]);
            }
            swap(dp1, dp2);
        }
        return dp1[n - 1];
    }
};

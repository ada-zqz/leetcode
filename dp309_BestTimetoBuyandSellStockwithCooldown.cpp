#define MAX(a, b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) {
            return 0;
        }
        if(n == 2) {
            return MAX(0, prices[1] - prices[0]);
        }
        // 到i为止，最后一次buy/sell操作对应的最大收益
        vector<int> buy(n), sell(n, 0);
        buy[0] = -prices[0];
        sell[1] = MAX(0, prices[1] - prices[0]);
        buy[1] = MAX(-prices[0], -prices[1]);
        for(int i = 2; i < n; i++) {
            // 保证sell之前已经买过了
            sell[i] = MAX(sell[i - 1], buy[i - 1] + prices[i]);
            buy[i] = MAX(buy[i - 1], sell[i - 2] - prices[i]);
        }
        return sell[n - 1];
    }
};

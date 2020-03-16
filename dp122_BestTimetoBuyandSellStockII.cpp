class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        vector<int> buy(n), sell(n);  //到i为止，买卖的最大值
        buy[0] = -prices[0];
        sell[0] = 0;
        for(int i = 1; i < n; i++) {
            // 不买/之前卖了现在买
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
            // 不卖/现在卖了，之前完成买的操作
            sell[i] = max(sell[i - 1], prices[i] + buy[i - 1]);
        }
        return sell[n - 1];
    }
};

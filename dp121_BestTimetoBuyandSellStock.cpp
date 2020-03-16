class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) {return 0;}
        int sell = -prices[0];
        int buy = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            sell = max(sell, prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        return max(0, sell);
    }
};

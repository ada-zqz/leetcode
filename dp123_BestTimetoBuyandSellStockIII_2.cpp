class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2){return 0;}
        int buy1 = 1 << 30, buy2 = 1 << 30;
        int sell1 = 1 << 31, sell2 = 1 << 31;
        for(int i = 0; i < n; i++) {
            buy1 = min(buy1, prices[i]);
            sell1 = max(sell1, prices[i] - buy1);
            buy2 = min(buy2, prices[i] - sell1);
            sell2 = max(sell2, prices[i] - buy2);
        }
        return sell2;
    }
};

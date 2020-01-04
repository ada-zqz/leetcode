class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) {return 0;}
        int buy = prices[0], sell = prices[0];
        int pro = sell - buy;
        int temp = -1;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] - sell > 0) {
                sell = prices[i];
                pro = sell - buy;
            }
            if((temp != -1) && ((prices[i] - temp) > pro)) {
                buy = temp;
                sell = prices[i];
                pro = sell - buy;
                temp = -1;
            }
            if(prices[i] - buy < 0) {
                if(temp == -1) {
                    temp = prices[i];
                }
                else{
                    if(prices[i] < temp) {
                        temp = prices[i];
                    }
                }
            }
        }
        return pro;
    }
};

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2){return 0;}
        vector<int> min(n), max(n), maxpro1(n), maxpro2(n);
        min[0] = prices[0];
        max[n - 1] = prices[n - 1];
        
        for(int i = 1; i < n; i++) {
            min[i] = MIN(min[i - 1], prices[i]);            
            max[n - 1 - i] = MAX(max[n - i], prices[n - 1 - i]);
        }

        maxpro1[0] = maxpro2[n - 1] = 0;
        for(int i = 1; i < n; i++) {
            //第i天卖出能获得的第一次卖出的最大利润 (prices[i] - min[i])
            //第i天（包括）前处理完第一次交易能得到的最大利润
            maxpro1[i] = MAX(maxpro1[i - 1], (prices[i] - min[i])); 
            //第n-1-i天买入，第二次能卖出的最大利润 (max[n - 1 - i] - prices[n - 1 - i])
            //第n-1-i天（包括）后处理完第二次交易能得到的最大利润
            maxpro2[n - 1 - i] = MAX(maxpro2[n - i], (max[n - 1 - i] - prices[n - 1 - i])); 
        }
        
        int pro = 0;
        for(int i = 1; i < n - 1; i++) {
            pro = MAX(pro, maxpro1[i] + maxpro2[i + 1]);
        }
        pro = MAX(pro, maxpro1[n - 1]);
        return pro;
    }
};

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) {return 0;}
        vector<int> min(n);
        vector<int> max(n);
        int pro = 0;
        min[0] = prices[0]; 
        max[n - 1] = prices[n - 1];
        
        for(int i = 1; i < n; i++) {
            min[i] = MIN(min[i - 1], prices[i]);
            max[n - 1 - i] = MAX(max[n - i], prices[n - 1 - i]);
        }
        for(int i = 1; i < n; i++) {
            pro = MAX(pro, max[i] - min[i]);
        }
        return pro;
    }
};

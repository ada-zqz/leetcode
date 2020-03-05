class Solution {
public:
    int mod = pow(10, 9) + 7;  //10^9 + 7
    int countOrders(int n) {
        if(n == 1) return 1;
        long dp, pre = 1;
        
        for(int i = 2; i <= n; i++) {
            dp = pre * ((1 + 2 * (i - 1)) * i) % mod; //前面2*(i - 1)个已排好，插空
            pre = dp;
        }
        return int(pre);
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 1;
        vector<int> add(k, 0); // 前一个乘p的数
        for(int i = 1; i < n; i++) {
            int addj;
            for(int j = 0; j < primes.size(); j++) {
                if(dp[i] > dp[add[j]] * primes[j]) {
                    //从最小的数开始乘倍数
                    dp[i] = dp[add[j]] * primes[j];
                    addj = j;
                };
            }
            add[addj]++;  //最小的数乘过了，下次乘以次小的数
            if(dp[i] == dp[i - 1]) {
                dp[i] = INT_MAX;
                i--;
            }
        }
        return dp[n - 1];
    }
};

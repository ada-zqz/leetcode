class Solution {
public:
    int MOD = 1e9 + 7;
    int numOfWays(int n) {
        vector<vector<long long>> dp(2, vector<long long>(2, 0));
        dp[0][0] = 6; //不同的颜色
        dp[0][1] = 6; //1-3相同，2不同
        for(int i = 1; i < n; i++) {
            dp[i & 1][0] = dp[(i - 1) & 1][0] * 2 + dp[(i - 1) & 1][1] * 2;
            dp[i & 1][1] = dp[(i - 1) & 1][0] * 2 + dp[(i - 1) & 1][1] * 3;
            dp[i & 1][0]  = dp[i & 1][0] % MOD;
            dp[i & 1][1]  = dp[i & 1][1] % MOD;
        }
        return (dp[(n - 1) & 1][0] + dp[(n - 1) & 1][1]) % MOD;
    }
};

class Solution {
private:
    int mod = 1e9 + 7;
public:
    int numOfArrays(int n, int m, int K) {
        if(K == 0) return 0;
        // dp[i][j][k] 到第i个位置为止，最大值为j，满足条件k次的次数
        int dp[55][105][55];
        memset(dp, 0, sizeof(dp));
        for(int j = 1; j <= m; j++) dp[1][j][1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= m; j++) { // i-1的取值
                for(int k = 1; k <= i; k++) {
                    for(int jj = 1; jj <= m; jj++) { // i的取值
                        if(jj <= j) {
                            dp[i][j][k] += dp[i - 1][j][k];
                            dp[i][j][k] %= mod;
                        }
                        else {
                            dp[i][jj][k + 1] += dp[i - 1][j][k];
                            dp[i][jj][k + 1] %= mod;
                        }
                    }
                }
            }
        }
        int res = 0;
        for(int j = 1; j <= m; j++) {
            res += dp[n][j][K];
            res %= mod;
        }
        return res;
    }
};

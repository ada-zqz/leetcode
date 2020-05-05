class Solution {
public:
    const int MOD = 1e9 + 7;
    int dieSimulator(int n, vector<int>& rollMax) {
        int dp[5005][6][16];
        memset(dp, 0, sizeof(dp));
        // dp[i][j][k] 第i个位置第k次出现j的所有可能
        // 初始化
        for(int j = 0; j < 6; j++) {
            dp[1][j][1] = 1;
        }
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < 6; j++) {
                for(int k = 1; k <= rollMax[j]; k++) {
                    // i的位置出现j，并且连续出现了k次
                    if(k == 1) {
                        for(int l = 0; l < 6; l++) {
                        //for(int l = 0; l != j && l <6; l++) l==j时for循环就结束了，写法不对
                            if(l == j) continue;
                            // i-1出现l(!=j)
                            for(int m = 1; m <= rollMax[l]; m++) {
                                dp[i][j][k] += dp[i - 1][l][m];
                                dp[i][j][k] %= MOD;
                            }
                        }
                    }
                    else {
                        dp[i][j][k] += dp[i - 1][j][k - 1];
                        dp[i][j][k] %= MOD;
                    }
                }
            }
        }
        int res = 0;
        for(int j = 0; j < 6; j++) {
            for(int k = 1; k <= rollMax[j]; k++) {
                res += dp[n][j][k];
                res %= MOD;
            }
        }
        return res;
    }
};

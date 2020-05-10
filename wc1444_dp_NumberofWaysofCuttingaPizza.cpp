class Solution {
public:
    const int MOD = 1e9 + 7;
    int ways(vector<string>& pizza, int K) {
        int m = pizza.size();
        int n = pizza[0].size();
        int pos[55][55];
        memset(pos, 0, sizeof(pos));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) 
                if(pizza[i][j] == 'A') {
                    pos[i][j] = true;
                }
        }
        int loc[55][55][55][55];  //(i,j)(k,l)has apple?
        memset(loc, 0, sizeof(loc));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = i + 1; k <= m; k++) {
                    for(int l = j + 1; l <= n; l++) {
                        if(loc[i][j][k][l - 1] || loc[i][j][k - 1][l] || pos[k - 1][l - 1]) loc[i][j][k][l] = true;
                    }
                }
            }
        }
        
        int dp[55][55][15];
        memset(dp, 0, sizeof(dp));
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(loc[i][j][m][n]) {
                    dp[i][j][0] = 1;
                }
                // vertically
                for(int l = j + 1; l <= n - 1; l++) {
                    for(int k = 0; k < K - 1; k++) {
                        if(loc[i][j][m][l] && dp[i][l][k]) {
                            dp[i][j][k + 1] = (dp[i][j][k + 1] + dp[i][l][k]) % MOD;
                        }
                    }
                }
                // horizontally
                for(int l = i + 1; l <= m - 1; l++) {
                    for(int k = 0; k < K - 1; k++) {
                        if(loc[i][j][l][n] && dp[l][j][k]) {
                            dp[i][j][k + 1] = (dp[i][j][k + 1] + dp[l][j][k]) % MOD;
                        }  
                    }
                }
                
            }
        }
        return dp[0][0][K - 1];
    }
};

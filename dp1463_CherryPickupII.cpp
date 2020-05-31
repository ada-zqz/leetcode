class Solution {
public:
    int cherryPickup(vector<vector<int>>& gd) {
        // 我为人人，而不是人人为我（更麻烦）
        int m = gd.size();
        int n = gd[0].size();
        int dp[75][75][75];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) dp[i][j][k] = INT_MIN;
            }
        }
        
        dp[0][0][n - 1] = gd[0][0] + gd[0][n - 1];
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = j; k < n; k++) {
                    if(dp[i][j][k] == INT_MIN) continue; //不能往下走
                    for(int l = -1; l <= 1; l++) {
                        for(int p = -1; p <= 1; p++) {
                            if(j + l < 0 || j + l >= n || k + p < 0 || k + p >= n) continue;
                            if(j + l == k + p) dp[i + 1][j + l][k + p] = max(dp[i + 1][j + l][k + p], gd[i + 1][j + l] + dp[i][j][k]);
                            else if(j + l < k + p) dp[i + 1][j + l][k + p] = max(dp[i + 1][j + l][k + p], gd[i + 1][j + l] + gd[i + 1][k + p] + dp[i][j][k]);
                        }
                    }
                }
            }
        }
        
        int res = 0;
        for(int j = 0; j < n; j++) {
            for(int k = j; k < n; k++)    
                res = max(res, dp[m - 1][j][k]);
        }
        return res;
    }
};

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int dp[105][105][25]; //以第i个人为最后一人形成j个邻居，第i个涂k个颜色，花费最少
        for(int i = 0; i < m; i++) {
            for(int k = 1; k <= n; k++) {
                for(int j = 0; j <= target; j++) dp[i][j][k] = 0x3f3f3f;
            }
        }
        // 第1个人
        if(houses[0] == 0) {
            for(int k = 1; k <= n; k++) {
                dp[0][1][k] = cost[0][k - 1];
            }
        }
        else {
            dp[0][1][houses[0]] = 0;
        }
        
        for(int i = 1; i < m; i++) {
            if(houses[i]) {
                //涂好颜色
                for(int j = 1; j <= target; j++) {
                    for(int k = 1; k <= n; k++) {
                        if(k == houses[i]) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                        else dp[i][j + 1][houses[i]] = min(dp[i][j + 1][houses[i]], dp[i - 1][j][k]);
                    }
                }
                
            }
            else {
                //随便涂颜色
                for(int k = 1; k <= n; k++) {
                    for(int j = 1; j <= target; j++) {
                        for(int l = 1; l <= n; l++) {
                            if(l == k) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][l] + cost[i][k - 1]);
                            else dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][l] + cost[i][k - 1]);
                        }
                    }
                }
            }
        }
        
        int res = 0x3f3f3f;
        for(int k = 1; k <= n; k++) {
            res = min(res, dp[m - 1][target][k]);
        }
        return res == 0x3f3f3f ? -1 : res;
    }
};

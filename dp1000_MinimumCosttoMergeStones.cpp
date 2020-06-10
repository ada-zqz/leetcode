class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if((n - 1) % (K - 1)) return -1;
        vector<int> sm(n + 1, 0);
        for(int i = 0; i < n; i++) sm[i + 1] = sm[i] + stones[i];
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int m = K; m <= n; m++) {
            for(int i = 0; i + m <= n; i++) {
                int j = i + m - 1;
                dp[i][j] = INT_MAX;
                for(int mid = i; mid < j; mid += K - 1) {
                    // 首次计算会得到dp[i][j] = 0
                    // 之后计算举例：dp[0][0] + dp[1][3] = dp[1][3]
                    // dp[0][3] = min(dp[1][3], dp[0][2])
                    // dp[0][4] = min(dp[0][2], dp[1][3], dp[2][4])
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                }
                if((j - i) % (K - 1) == 0) 
                    // 最后一次合并加的值相同sm[j + 1] - sm[i]
                    // dp[i][j]的最小依赖于[i, j]中倒数第二次合并的最小值
                    // [0 - 5]: [0-2],[1-3],[2-4],[3-5], K=3
                    dp[i][j] += sm[j + 1] - sm[i];
            }
        }
        
        return dp[0][n - 1];
    }
};

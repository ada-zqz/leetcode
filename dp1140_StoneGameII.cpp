class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        if(n == 0) return 0;
        // dp[i][j] start at i, with M = j
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // 从后往前的累加和
        vector<int> psum(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) psum[i] = psum[i + 1] + piles[i];

        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 1; j--) {
                for(int x = 1; x <= 2 * j && i + x <= n; x++)
                    dp[i][j] = max(dp[i][j], psum[i] - dp[i + x][max(j, x)]);
            }
        }
        return dp[0][1];
    }
};

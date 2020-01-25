class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        // 由(i, j)走N步出格子 == 从格子外走N步到(i, j)
        static int MOD = 1000000007;
        unsigned int dp[51][50][50];
        for(int nowN = 1; nowN <= N; nowN++) {
            for(int r = 0; r < m; r++) {
                for(int c = 0; c < n; c++) {
                    // at most move N (not exactly move N)
                    dp[nowN][r][c] = (((r == 0) ? 1 : dp[nowN - 1][r - 1][c]) + ((r == m - 1) ? 1 : dp[nowN - 1][r + 1][c]) + ((c == 0) ? 1 : dp[nowN - 1][r][c - 1]) + ((c == n - 1) ? 1 : dp[nowN - 1][r][c + 1])) % MOD;
                }
            }
        }
        return dp[N][i][j];
    }
};

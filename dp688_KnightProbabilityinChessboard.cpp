class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        if(K == 0)
            return 1;
        float dp[101][25][25];
        memset(dp, 0, sizeof(dp));
        return prob(N, K, r, c, dp);
    }
    
    float prob(int& N, int K, int r, int c, float (&dp)[101][25][25]) {
        if(r < 0 || r >= N || c < 0 || c >= N) {
            return 0;
        }
        if(K == 0) {
            return 1;
        }
        if(dp[K][r][c] != 0) {
            return dp[K][r][c];
        }
        dp[K][r][c] =  0.125 * (prob(N, K - 1, r - 1, c + 2, dp) + prob(N, K - 1, r - 1, c - 2, dp) + prob(N, K - 1, r - 2, c + 1, dp) + prob(N, K - 1, r - 2, c - 1, dp) + prob(N, K - 1, r + 1, c + 2, dp) + prob(N, K - 1, r + 1, c - 2, dp) + prob(N, K - 1, r + 2, c + 1, dp) + prob(N, K - 1, r + 2, c - 1, dp));
        return dp[K][r][c];
    }
};

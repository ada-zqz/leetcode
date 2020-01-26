struct DIR {
    int h, v;
    DIR(int horizon, int vertical): h(horizon), v(vertical) {}
};

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        if(K == 0)
            return 1;
        float dp[101][25][25];  //dp[k][i][j]存储从(i, j)走k步存活的概率
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                dp[0][i][j] = 1;
            }
        }
        // dir存储可以走的8个方向
        DIR dir[8] = {DIR(1, 2), DIR(2, 1), DIR(2, -1), DIR(1, -2),
                      DIR(-1, -2), DIR(-2, -1), DIR(-2, 1), DIR(-1, 2)};
        
        for(int nowK = 1; nowK <= K; nowK++) {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    for(int l = 0; l < 8; l++) {
                        int ip = i + dir[l].h, jp = j + dir[l].v;
                        if(ip >= 0 && ip < N && jp >= 0 && jp < N) {
                            dp[nowK][i][j] +=  (1./8) * dp[nowK - 1][ip][jp];
                        }
                    }
                }
            }
        }
        return dp[K][r][c];
    }
};

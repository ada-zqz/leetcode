long long dp[101][101];

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        for(int i=1; i<=obstacleGrid.size(); i++) {
            for(int j=1; j<=obstacleGrid[i-1].size(); j++) {
                // printf("%d %d %d -s\n", i, j, dp[i][j]);
                if(obstacleGrid[i - 1][j - 1] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i == 1 && j == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[obstacleGrid.size()][obstacleGrid[0].size()];
    }
};

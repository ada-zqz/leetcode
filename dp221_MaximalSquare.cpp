#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define min(a, b, c) MIN(MIN(a, b), c)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int temp, maxs = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!i || !j || matrix[i][j] == '0') { //第1行或者第1列或者本身为0，就等于自身
                    dp[i][j] = matrix[i][j] - '0';
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + (matrix[i][j] - '0');
                }
                if(dp[i][j] > maxs) {
                        maxs = dp[i][j];
                }
            }
        }
        return maxs*maxs;
    }
};

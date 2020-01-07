#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define min(a, b, c) MIN(MIN(a, b), c)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) {return 0;}
        int n = matrix[0].size();
        vector<int> v(n + 1, 0);
        vector<vector<int>> dp(m + 1, v);
        int temp, maxs = 0;
        
        for(int i = 1; i < m + 1; i++) {
            for(int j = 1; j < n + 1; j++) {
                temp = matrix[i - 1][j - 1] - '0';
                if(temp) {
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + temp;
                    if(dp[i][j] > maxs) {
                        maxs = dp[i][j];
                    }
                }
                else { //present 0
                    dp[i][j] = 0;
                }
            }
        }
        return maxs*maxs;
    }
};

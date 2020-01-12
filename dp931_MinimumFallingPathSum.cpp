#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define min(a, b, c) MIN(MIN(a, b), c)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if(A.size() == 1) {return A[0][0];}
        vector<int> dp(A.size());
        
        for(int i = 1; i < A.size(); i++) {
            for(int j = 0; j < A.size(); j++) {
                if(j == 0) {
                    dp[j] = MIN(A[i - 1][j], A[i - 1][j + 1]) + A[i][j];
                    continue;
                }
                if(j == A.size() - 1) {
                    dp[j] = MIN(A[i - 1][j - 1], A[i - 1][j]) + A[i][j];
                    continue;
                }
                dp[j] = min(A[i - 1][j - 1], A[i - 1][j], A[i - 1][j + 1]) + A[i][j];
            }
            swap(dp, A[i]);
        }
        
        for(int i = 1; i < A.size(); i++) {
            A[A.size() - 1][0] = MIN(A[A.size() - 1][0], A[A.size() - 1][i]);
        }
        
        return A[A.size() - 1][0];
    }
};

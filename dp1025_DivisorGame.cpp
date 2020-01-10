class Solution {
public:
    bool divisorGame(int N) {
        if(N == 2 or N == 4) {return true;}
        if(N == 1 or N == 3) {return false;}
        vector<bool> dp(N, 0);
        dp[2] = 1;
        dp[4] = 1;
        
        for(int i = 5; i <= N; i++) {
            for(int j = 1; j < i/2; j++) {
                if((i % j == 0) && (dp[i - j] == 0)) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[N];
    }
};

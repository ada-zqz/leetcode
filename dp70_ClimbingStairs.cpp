int dp[1000];
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) {
            dp[1] = 1;
            return 1;
        }
        if(n == 2) {
            dp[2] = 2;
            return 2;
        }
        if(dp[n - 1] == 0) {dp[n - 1] = climbStairs(n - 1);}
        if(dp[n - 2] == 0) {dp[n - 2] = climbStairs(n - 2);}
        return  dp[n - 1] + dp[n - 2];
    }
};

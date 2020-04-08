class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 1 << 31));
        return sub(piles, dp, 0, n - 1) > 0 ? true : false;
    }
    
    //[l, r] 先取的比后取的取值差多少
    int sub(vector<int>& piles, vector<vector<int>>& dp, int l, int r) {
        if(l == r) {
            dp[l][r] = piles[l];
            return dp[l][r];
        }
        if(dp[l][r] != 1 << 31) return dp[l][r];
        if(dp[l + 1][r] == 1 << 31)  dp[l + 1][r] = sub(piles, dp, l + 1, r);
        dp[l][r] = piles[l] - dp[l + 1][r];
        if(dp[l][r - 1] == 1 << 31)  dp[l][r - 1] = sub(piles, dp, l, r - 1);
        dp[l][r] = max(dp[l][r], piles[r] - dp[l][r - 1]);
        return dp[l][r];
    }
};

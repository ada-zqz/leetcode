class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        if(satisfaction[n - 1] <= 0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int res = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i; j <= n; j++) {
                dp[i][j] = dp[i][j - 1] + (j - i + 1) * satisfaction[j - 1];
            }
            res = max(res, dp[i][n]);
        }
        return res;
    }
};

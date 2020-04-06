class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, 1 << 31);
        dp[n] = 0;
        
        // dp[i]: 从第i个开始选择时，能多多少value
        for(int i = n - 1; i >= 0; i--) {
            int m = 0;
            for(int j = i, cs = 1; j < n && cs <= 3; j++, cs++) {
                m += stoneValue[j];
                dp[i] = max(dp[i], m - dp[j + 1]);
            }
        }
        if(dp[0] > 0) return "Alice";
        if(dp[0] < 0) return "Bob";
        return "Tie";
    }
};

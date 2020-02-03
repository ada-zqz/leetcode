class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        
        for(int i = 0; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j - 1] == '*') {
                    // '*'匹配0个字符 or 匹配当前字符 or 匹配多个字符
                    dp[i][j] = dp[i][j - 1] || (i > 0 && (dp[i - 1][j - 1] || dp[i - 1][j])); 
                }
                else if(i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?')) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[n][m];
    }
};

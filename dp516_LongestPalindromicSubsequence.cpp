class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() == 1)
            return 1;
        //dp[i][j]存放以s[i]结尾，以s[j]开始的最长的回文长度
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));   
        
        for(int i = 1; i < s.size(); i++) {
            dp[i][i] = 1;
            for(int j = i - 1; j >= 0; j--) {
                if(s[i] == s[j]) { //i - j > 1
                    dp[i][j] = dp[i - 1][j + 1] + 2;
                }
                else { 
                    dp[i][j] = max(dp[i][j + 1], dp[i - 1][j]);
                }
            }
        }
        return dp[s.size() - 1][0];
    }//类似最长公共子序列
};

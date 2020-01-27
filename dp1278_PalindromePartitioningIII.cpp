class Solution {
public:
    int palindromePartition(string s, int k) {
        if(k == s.size())
            return 0;
        int n = s.size();        
        // pd[j][i]表示[j,i]内的字符串是回文所要改变的最少的字符数
        vector<vector<int>> pd(n, vector<int>(n, 0));
        // dp[i][k]表示[0,i]内的字符串分成k+1份需要的改变的最少字符数
        vector<vector<int>> dp(n, vector<int>(k, 1<<30));
        
        dp[0][0] = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] != s[i - 1]) {
                pd[i - 1][i] = 1;
            }
            for(int j = i - 2; j >= 0; j--) {
                if(s[i] == s[j]) {
                    pd[j][i] = pd[j + 1][i - 1];
                }
                else {
                    pd[j][i] = pd[j + 1][i - 1] + 1;
                }
            }
            dp[i][0] = pd[0][i];  //只有1份
            for(int l = 1; l < k; l++) {
                if(l <= i) {  //i+1个字符分成l+1份，不需要改变字符, j >= l - 1
                    for(int j = 0; j < i; j++) {
                        dp[i][l] = min(dp[i][l], dp[j][l - 1] + pd[j + 1][i]);  
                    }
                }
            }
        }
        return dp[n - 1][k - 1];
    }
};

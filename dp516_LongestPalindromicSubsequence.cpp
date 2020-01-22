class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() == 1)
            return 1;
        vector<int> dp(s.size(), 1);   //dp[i]存放到i为止，最长的回文长度
        vector<int> pres(s.size(), 0); //pres[i]存放到i为止，最长回文的第一个字母的位置
        for(int i = 1; i < s.size(); i++) { //先处理字母相等的回文，每次只加1
            pres[i] = i;
            for(int j = i - 1; j >= 0; j--) {
                if(s[i] == s[j]) {
                    dp[i] = dp[j] + 1;
                    pres[i] = pres[j];
                    break;
                }                
            }
        }
        for(int i = 1; i < s.size(); i++) {
            for(int j = i - 1; j >= 0; j--) { //根据i之前的回文推断i出的回文
                // cout<<i<<j<<dp[i]<<pres[i]<<dp[j]<<pres[j]<<endl;
                if(dp[j] > dp[i]) {
                    dp[i] = dp[j];
                    pres[i] = pres[j];
                }
                if(pres[j] > 0) { //if(pres[j] == 0) s[i]加不上去
                    for(int k = pres[j] - 1; k >= 0; k--) {
                        if(s[k] == s[i]) {
                            if(dp[j] + 2 > dp[i]) {
                                dp[i] = dp[j] + 2;
                                pres[i] = k;
                                break;
                            }
                        }
                    }
                }
            }
        }
        return dp[s.size() - 1];
    }
};

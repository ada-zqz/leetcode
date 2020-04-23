class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> dp(5, 0);
        for(int i = 0; i < croakOfFrogs.size(); i++) {
            char s = croakOfFrogs[i];
            if(s == 'c') {
                dp[0]++;
                // 完成叫声的青蛙可以开始新的叫声
                dp[4] = max(0, dp[4] - 1);
            }
            else if(s == 'r') {
                if(dp[0]) {
                    dp[1]++;
                    dp[0]--;
                }
                else {
                    // r前面要有c
                    return -1;
                }
            }
            else if(s == 'o') {
                if(dp[1]) {
                    dp[2]++;
                    dp[1]--;
                }
                else {
                    return -1;
                }
            }
            else if(s == 'a') {
                if(dp[2]) {
                    dp[3]++;
                    dp[2]--;
                }
                else {
                    return -1;
                }
            }
            else if(s == 'k') {
                if(dp[3]) {
                    dp[4]++;
                    dp[3]--;
                }
                else {
                    return -1;
                }
            }
        }
        // 有叫声未完成
        if(dp[0] || dp[1] || dp[2] || dp[3]) return -1;
        return dp[4];
    }
};

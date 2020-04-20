class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<long long> dp(n, 0);
        for(int i = 0; i < n; i++) {
            long long cur = 0;
            for(int j = i; j >= 0; j--) {
                if(pow(10, i - j) > k) break;
                cur += (s[j] - '0') * pow(10, i - j);
                if(cur > k) break;
                if((s[j] - '0') == 0) continue;
                // 1 <= cur <= k
                if(j == 0) {
                    dp[i] += 1;
                }
                else dp[i] += dp[j - 1];
                dp[i] %= mod;
            }
        }
        return dp[n - 1];
    }
};

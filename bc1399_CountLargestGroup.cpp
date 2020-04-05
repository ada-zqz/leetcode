class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> dp(37, 0);
        int mx = 0;
        for(int i = 1; i <= n; i++) {
            int cs = countsum(i);
            dp[cs]++;
            mx = max(mx, dp[cs]);
        }
        int res = 0;
        for(int i: dp) {
            if(i == mx) res++;
        }
        return res;
    }
    int countsum(int n) {
        if(n / 10 == 0) return n;
        else return n % 10 + countsum(n / 10);
    }
};

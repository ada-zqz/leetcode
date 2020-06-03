？*
1 <= n, a, b, c <= 10^9
1 <= a * b * c <= 10^18
*/
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        vector<int> dp(n, 0);
        int na = 1, nb = 1, nc = 1;
        for(int i = 0; i < n; i++) {
            dp[i] = min(na * a, min(nb * b, nc * c));
            // 相同的乘积由于下面三个判断都++了
            if(dp[i] == na * a) na++;
            if(dp[i] == nb * b) nb++;
            if(dp[i] == nc * c) nc++;
        }
        return dp[n - 1];
    }
};

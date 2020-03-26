class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        static vector<vector<int>> dp(1e5 + 1, vector<int>(2, 0));
        dp[1][0] = 1; //divisors
        dp[1][1] = 1; //sum
        dp[2][0] = 2;
        dp[2][1] = 3;
        dp[3][0] = 2;
        dp[3][1] = 4;
        dp[4][0] = 3;
        dp[4][1] = 7;
        dp[5][0] = 2;
        dp[5][1] = 6;
        int ans = 0;
        for(int v: nums) {
            if(dp[v][0] > 0 && dp[v][0] != 4) continue;
            vector<int> dv = findv(v, dp);
            if(dv[0] == 4) ans += dv[1];
        }
        return ans;
    }
    vector<int> findv(int v, vector<vector<int>> & dp) {
        if(dp[v][0] != 0) return dp[v];
        if(v % 16 == 0 || (v % 2 == 0 && v % 3 == 0 && v % 5 == 0)) {
            dp[v][0] = 5;
            return dp[v];
        }
        int dv = 2;
        int sm = 1 + v;
        for(int i = 2; i <= sqrt(v); i++) {
            if(v % i == 0) {
                vector<int> sub1 = findv(i, dp);
                vector<int> sub2 = findv(v / i, dp);
                if(sub1[0] > 3 || sub2[0] > 3) {
                    dv = 5;
                    break;
                }
                if(v / i == i) {
                    dv++;
                    sm += i;
                }
                else {
                    dv += 2;
                    sm += i + v / i;
                }
            }
            if(dv > 4) break;
        }
        dp[v][0] = dv;
        dp[v][1] = sm;
        return dp[v];
    }
};

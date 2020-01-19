class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp({0});
        while(dp.size() <= n) {
            int ns = dp.size();
            int leastSq = 1 << 30;
            for(int j = 1; j <= sqrt(ns); j++) {
                leastSq = min(leastSq, dp[ns - j*j] + 1);
            }
            dp.push_back(leastSq);
        }
        return dp[n];
    }
};

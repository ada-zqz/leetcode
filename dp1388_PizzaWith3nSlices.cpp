class Solution {
public:
    int ans = 0;
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size() / 3;
        // 选中的蛋糕不能相邻
        // 首尾不能同时选中
        vector<int> l1 = vector<int>(slices.begin(), slices.end() - 1);
        vector<int> l2 = vector<int>(slices.begin() + 1, slices.end());
        return max(sub(l1, n), sub(l2, n));
    }
    int sub(vector<int> v, int n) {
        // dp[i][j]: 截至[1,i], 选取j个蛋糕得到的最大值
        int m = v.size() + 2;
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n + 1, 0));
        for(int i = 2; i < m; i++) {
            for(int j = 1; j <= n; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + v[i - 2]);
            }
            ans = max(ans, dp[i][n]);
        }
        return ans;
    }
};

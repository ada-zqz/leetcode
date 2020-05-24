class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        dp[0][0] = nums1[0] * nums2[0];
        for(int j = 1; j < m; j++) dp[0][j] = max(dp[0][j - 1], nums1[0] * nums2[j]);
        for(int i = 1; i < n; i++) dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), max(0, dp[i - 1][j - 1]) + nums1[i] * nums2[j]);
            }
        }
        return dp[n - 1][m - 1];
    }
};

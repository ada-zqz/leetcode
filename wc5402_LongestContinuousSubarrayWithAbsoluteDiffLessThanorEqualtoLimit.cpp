class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int j = 0; j < n; j++) {
            dp[j][j] = 0;
            for(int i = j - 1; i >= 0; i--) {
                int diff = abs(nums[i] - nums[j]);
                dp[i][j] = max(dp[i + 1][j], max(dp[i][j - 1], diff));
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(dp[i][j] <= limit) res = max(res, j - i + 1);
            }
        }
        return res;
    }
};

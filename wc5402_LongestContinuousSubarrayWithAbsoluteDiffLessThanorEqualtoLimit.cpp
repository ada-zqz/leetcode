class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int res = 1;
        int vmin, vmax;
        vector<int> dp(n, -1);
        for(int i = 0; i < n; i++) {
            vmin = vmax = nums[i];
            dp[i] = 0;
            if(i - 1 + res >= n) break;
            for(int j = i + 1; j < n; j++) {
                dp[j] = max(dp[j - 1], max(abs(nums[j] - vmin), abs(nums[j] - vmax)));
                if(dp[j] <= limit) res = max(res, j - i + 1);
                else break;
                if(nums[j] > vmax) vmax = nums[j];
                if(nums[j] < vmin) vmin = nums[j];
            }
        }
        return res;
    }
};

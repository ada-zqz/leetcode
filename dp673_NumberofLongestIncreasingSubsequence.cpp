class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int nn = nums.size();
        if(nn == 1)
            return 1;
        
        vector<int> dp(nn, 1);  //以nums[i]结尾的最长上升子序列大小
        vector<int> nl(nn, 1);  //以nums[i]结尾的最长上升子序列的个数
        int retn = 1, vmax = 1;
        for(int i = 1; i < nn; i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(nums[i] > nums[j]) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        nl[i] = nl[j];
                    }
                    else {
                        if(dp[i] == dp[j] + 1) {
                            nl[i] += nl[j];
                        }
                    }
                    continue;
                }
                if(nums[i] == nums[j]) {
                    if(dp[i] < dp[j]) {
                        dp[i] = dp[j];
                        nl[i] = nl[j];
                        break;
                    }
                }
            }
            if(vmax < dp[i]) {
                vmax = dp[i];
                retn = nl[i];
                continue;
            }
            if(vmax == dp[i]) {
                retn += nl[i];
            }
            // cout << i << ' ' << vmax << ' ' << dp[i] << ' ' << nl[i] << endl;
        }
        return retn;
    }
};

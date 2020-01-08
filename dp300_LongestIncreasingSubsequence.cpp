#define MAX(a, b) ((a) > (b) ? (a) : (b))
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n, 1); //以i为终点的最长上升子序列的长度
        int lis = 1;
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = MAX(dp[i], dp[j] + 1);
                }
            }
            lis = MAX(lis, dp[i]);
        }
        return lis;
    }
};

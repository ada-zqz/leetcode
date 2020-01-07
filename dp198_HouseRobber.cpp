class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {return 0;}
        vector<int> dp(n);
        int pre;
        
        dp[0] = nums[0];
        pre = 0;
        if(n == 1) {return dp[0];}
        if(nums[1] > nums[0]) {
            dp[1] = nums[1];
            pre = 1;
        }
        else {
            dp[1] = dp[0];
        }
        if(n == 2) {return dp[1];}
        
        for(int i = 2; i < nums.size(); i++) {
            if(pre == i - 1) {
                if(dp[i - 2] + nums[i] > dp[i - 1]) {
                    dp[i] = dp[i - 2] + nums[i];
                    pre = i;
                }
                else {
                    dp[i] = dp[i - 1];
                }
            }
            else {
                dp[i] = dp[i - 1] + nums[i];
                pre = i;
            }
        }
        
        return dp[nums.size() - 1];
    }
};

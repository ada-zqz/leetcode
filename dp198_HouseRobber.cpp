# define MAX(a, b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {return 0;}
        vector<int> dp(n);
        
        if(n == 1) {return nums[0];}
        dp[0] = nums[0];
        if(nums[1] > nums[0]) {
            dp[1] = nums[1];
        }
        else {
            dp[1] = dp[0];
        }
        if(n == 2) {return dp[1];}
        
        for(int i = 2; i < nums.size(); i++) {
            dp[i] = MAX(dp[i - 2] + nums[i], dp[i - 1]);
        }
        
        return dp[nums.size() - 1];
    }
};

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return combination(nums, target, dp);
    }
    
    int combination(vector<int>& nums, int target, vector<int>& dp) {
        if(dp[target] != -1) {return dp[target];}
        if(target == 0) {return 1;}
        
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(target < nums[i]) {continue;}
            res += combination(nums, target - nums[i], dp);
        }
        dp[target] = res;
        return res;
    }
};

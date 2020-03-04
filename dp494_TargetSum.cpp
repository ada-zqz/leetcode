class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        //https://leetcode.com/problems/target-sum/discuss/97334/Java-(15-ms)-C%2B%2B-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation
        int sum = 0;
        for(auto n: nums) sum += n;
        if(sum < S || sum < -S || (sum + S) % 2) return 0;
        return findsum(nums, (sum + S) / 2);
    }
    int findsum(vector<int>& nums, int target) {
        vector<int> dp(target + 1); //dp[i]表示求和为i的组合数
        dp[0] = 1;
        for(auto n: nums) {
            for(int i = target; i >= n; i--) {
                dp[i] += dp[i - n];
            }
        }
        return dp[target];
    }
};

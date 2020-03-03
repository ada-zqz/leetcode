class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int len = nums.size();
        return dfs(len, nums, S);
    }
    int dfs(int i, vector<int>& nums, int s) {
        if(i == 0) {
            int m = 0;
            if(nums[i] == s) m += 1;
            if(nums[i] == -s) m += 1;
            return m;
        }
        return dfs(i - 1, nums, s - nums[i]) + dfs(i - 1, nums, s + nums[i]);
    }
};

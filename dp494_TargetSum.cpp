class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(auto n: nums) sum += n;
        if(sum < S) return 0;
        int len = nums.size();
        return dfs(len - 1, nums, S);
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

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int res = nums[0];
        int n = nums.size();
        vector<int> dp(n);  //初始化dp {nums[0]}, 之后就要不断push_back
        dp[0] = nums[0];
        deque<int> decrease {0};   // index
        // dp[i]: 最后一个数为nums[i]，对应的最大sum
        // decrease: 第一个数为dp[i - k], dp[i - k + 1], ..., dp[i - 1]的最大值
        // dp[i] = max(nums[i], nums[i] + decrease[0])
        // 如果dp[i - j] < dp[i]，dp[i - j]从decrease中删除，因为加入dp[i]后dp[i - j]永远不会用到了
        // 如果decrease[0] < i - k，删除，超过i - j <= k的范围了
        for(int i = 1; i < n; i++) {
            while(decrease[0] < i - k) {
                decrease.pop_front();
            }                        
            dp[i] = max(nums[i], dp[decrease[0]] + nums[i]);
            res = max(res, dp[i]);
            while(!decrease.empty() && dp[decrease.back()] <= dp[i]) {
                decrease.pop_back();
            }
            decrease.push_back(i);
        }
        return res;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int res = 1;
        vector<int> pre(n, -1);
        vector<int> now(n, -1);
        for(int j = 0; j < n; j++) {
            now[j] = 0;
            for(int i = j - 1; i >= 0; i--) {
                int diff = abs(nums[i] - nums[j]);
                now[i] = max(now[i + 1], max(pre[i], diff));
                if(now[i] <= limit) res = max(res, j - i + 1);
                else break;
            }
            swap(pre, now);
        }
        return res;
    }
};

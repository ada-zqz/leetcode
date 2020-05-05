class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int lo = 0, hi = 1e6;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            int count = 0;
            int j = 1;
            for(int i = 0; i < n - 1; i++) {
                // // 如果j还是i到n-1取值，时间复杂度是O(n^2)还得乘以binary search的log(1e6);
                // for(j = n - 1; j > i; j--) {
                //     if(nums[j] - nums[i] <= mid) break;
                // }
                // count += j - i;
                for(int k = j; k < n && (nums[k] - nums[i] <= mid); k++) {
                    // 如果nums[k] - nums[i]满足条件
                    // nums[k] - nums[i + 1]也满足条件
                    j++;
                }
                // nums[j - 1] - nums[i] <= mid; nums[j] - nums[i] > mid跳出循环
                count += j - i - 1;
                // nums[j - 1] - nums[i + 1] <= mid
            }
            if(count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};

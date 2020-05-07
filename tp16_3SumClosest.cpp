class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int cmp = 0x3f3f3f;  // 绝对值比较
        int res = cmp;       // closest结果
        
        for(int i = 0; i < n - 2; i++) {
            int t = target - nums[i];
            int lo = i + 1;
            int hi = n - 1;
            while(lo < hi) {
                int sm = nums[lo] + nums[hi];
                if(sm == t) return target;
                else if(sm > t) {
                    // a+b+c>target
                    if(cmp > (sm - t)) {
                        cmp = sm - t;
                        res = sm + nums[i];
                    }
                    hi--;  //sm偏大，hi--
                }
                else {
                    // a+b+c<target
                    if(cmp > (t - sm)) {
                        cmp = t - sm;
                        res = sm + nums[i];
                    }
                    lo++;
                }
            }
        }
        return res;
    }
};

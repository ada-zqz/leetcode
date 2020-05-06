class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        if(n == 0) return res;
        int lo = 0, hi = n - 1;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(nums[mid] >= target) hi = mid;
            else lo = mid + 1;
        }
        if(nums[lo] != target) return res;
        res[0] = lo;
        lo = 0, hi = n - 1;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(nums[mid] <= target) lo = mid + 1;
            else hi = mid;
        }
        if(nums[hi] == target)
            res[1] = hi;
        else if(hi - 1 >= 0 && nums[hi - 1] == target) res[1] = hi - 1;
        return res;
    }
};

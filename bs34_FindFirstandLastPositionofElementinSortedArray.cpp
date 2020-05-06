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
            else lo = mid + 1;  // nums[mid] < target
        }
        if(nums[lo] != target) return res;
        res[0] = lo;
        // lo = lo
        hi = n - 1;
        while(lo < hi) {
            int mid = (lo + hi) / 2 + 1;  // 0,1求mid为1
            if(nums[mid] == target) lo = mid;
            else hi = mid - 1;  // nums[mid] > target  因为lo从上面得到的res[0]开始
        }
        res[1] = hi;
        return res;
    }
};

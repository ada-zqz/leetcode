class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) hi = mid - 1; 
            //target < nums[hi + 1],位置应该在[lo, hi + 1]之间
            //若在hi+1，lo=hi后,lo++等于应该在的位置
            else lo = mid + 1;
            //target > nums[lo - 1],位置应该在[lo, hi]之间
        }
        return lo;
    }
};

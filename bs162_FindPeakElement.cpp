class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // nums[i] != nums[i + 1]
        // If num[i - 1] < num[i] > num[i + 1], then num[i] is peak
        // If num[i - 1] < num[i] < num[i + 1], then num[i + 1 ... n - 1] must contains a peak
        // If num[i - 1] > num[i] > num[i + 1], then num[0 ... i - 1] must contains a peak
        // If num[i - 1] > num[i] < num[i + 1], then both sides have peak
        int n = nums.size();
        if(n <= 1) return 0;
        int l = 0, r = n - 1, mid;
        while(l < r) {
            mid = (l + r) / 2;
            //只要l < r，mid + 1不越界
            if(nums[mid] < nums[mid + 1]) {
                //nums[n] = -inf
                l = mid + 1;
            }
            else {
                //nums[mid] > nums[mid + 1]
                //nums[-1] = -inf
                r = mid;
            }
        }
        return l;
    }
};

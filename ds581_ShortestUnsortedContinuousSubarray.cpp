class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int nmax = nums[0], nmin = nums[len - 1];
        int s = -1, e = -2;  //e - s + 1 = 0
        //从左到右，nums[i]比最大值要小的要排序
        //从右到左，nums[i]比最小值要大的要排序
        for(int i = 1; i < len; i++) {
            nmax = max(nmax, nums[i]);
            nmin = min(nmin, nums[len - i - 1]);
            if(nums[i] < nmax) e = i;  //一直找到最右边要排序的值
            if(nums[len - i - 1] > nmin) s = len - i - 1;  //一直找到最左边要排序的值
        }
        return e - s + 1;
    }
};

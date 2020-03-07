class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        vector<int> lmax(len), rmin(len);
        lmax[0] = nums[0];
        rmin[len - 1] = nums[len - 1];
        //从左到右，lmax[i]存储到i为止的最大值
        //从右到左，rmin[i]存储到i为止的最小值
        for(int i = 1; i < len; i++) {
            if(nums[i] > lmax[i - 1]) lmax[i] = nums[i];
            else lmax[i] = lmax[i - 1];
            if(nums[len - i - 1] < rmin[len - i]) rmin[len - i - 1] = nums[len - i - 1];
            else rmin[len - i - 1] = rmin[len - i];
        }
        int i = 0, j = len - 1;
        while(i < len && nums[i] <= rmin[i]) i++;
        while(j > i && nums[j] >= lmax[j]) j--;
        return j - i + 1;
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int bg = 0, end = len - 1;
        pair<int, int> v = quicksort(nums, bg, end);
        while(v.first != k - 1) {
            if(v.first >= k) {
                end = v.first - 1;
                v = quicksort(nums, bg, end);
            }
            else {
                // v.first < k - 1;
                bg = v.first + 1;
                v = quicksort(nums, bg, end);
            }    
        }
        return v.second;
    }
    pair<int, int> quicksort(vector<int>& nums, int bg, int end) {
        //快速排序，逆序
        int cmp = nums[end];  //取最后一个数为轴值
        int l = bg, r = end;
        while(l != r) {
            while(l < r && nums[l] >= cmp) l++;
            if(l < r) {
                nums[r] = nums[l];
                r--;
            }
            while(l < r && nums[r] <= cmp) r--;
            if(l < r) {
                nums[l] = nums[r];
                l++;
            }
        }
        nums[l] = cmp;
        return pair<int, int>(l, cmp);
    }
    
};

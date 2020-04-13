class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        int res = 0;
        int n = nums.size();
        int mul = 1;
        // 前一种解法是，nums[i], nums[i, i + 1], ..., nums[i, ..., j]
        // 乘到j时 < k, res += j - i + 1  nums[j], nums[j, j-1], ..., nums[j, ..., i]满足条件
        // 乘到j时 >= k, i++
        for(int i = 0, j = 0; j < n; j++) {
            mul *= nums[j];
            while(i <= j && mul >= k) {
                mul /= nums[i++];
            }
            res += j - i + 1;  //i=j+1时为0
        }
        return res;
    }
};

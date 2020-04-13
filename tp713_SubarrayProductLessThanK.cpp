class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        int r = 0;
        int mul = 1;
        for(int i = 0; i < n; i++) {
            if(i >= r) {
                mul = 1;  //重新开始乘
                r = i;
            }
            else mul /= nums[i - 1];
            res += (r - i);  //就j < k 之前算过肯定小于k
            for(int j = r; j < n; j++) {
                mul *= nums[j];
                if(mul < k) {
                    res++;
                    if(j == n - 1) r = n;
                }
                else {
                    r = j;
                    mul /= nums[j];
                    break;
                }
            }
        }
        return res;
    }
};

# define MAX(a, b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp0(n), dp1(n);
        
        if(n == 0) {return 0;}
        if(n == 1) {return nums[0];}
        if(n == 2) {return MAX(nums[0], nums[1]);}
        if(n == 3) {return MAX(MAX(nums[0], nums[1]), nums[2]);}

        for(int i = 0; i < n - 1; i++) { //不包括最后一个数
            if(i == 0) {dp0[i] = nums[i];}  //dp1[n-3]是nums下标[1, n-3]的数列的所求最大
            else {
                if(i == 1) {
                    dp0[i] = MAX(nums[0], nums[1]);
                    dp1[i] = nums[1];
                }
                else {
                    dp0[i] = MAX(dp0[i - 2] + nums[i], dp0[i - 1]);
                    if(i < n - 2) {
                        if(i == 2) {
                            dp1[i] = MAX(nums[1], nums[2]);
                        }
                        else {
                            dp1[i] = MAX(dp1[i - 2] + nums[i], dp1[i - 1]);
                        }
                    }
                }
            }
        }
        return MAX(dp0[n - 2], dp1[n - 3] + nums[n - 1]);
        
    }
};

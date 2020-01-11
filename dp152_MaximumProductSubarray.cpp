#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) {return nums[0];}
        
        int rmax = nums[0]; //final max
        int cmin = nums[0], cmax = nums[0]; //current contiguous min and max
        for(int i = 1; i < n; i++) {
            if(nums[i] < 0) {
                swap(cmin, cmax);
            }
            cmax = MAX(nums[i], cmax * nums[i]);
            cmin = MIN(nums[i], cmin * nums[i]);
            
            rmax = MAX(rmax, cmax);  // 遇到0也保证了最大值  
        }
        return rmax;
    }
};

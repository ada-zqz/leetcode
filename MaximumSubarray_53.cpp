//若前面>0，则可以相加，否则抛弃重置
//#define MAX(a, b) ((a) > (b) ? (a) : (b))

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max, temp, i;
        max = temp = nums[0];
        for(i=1; i<nums.size(); i++){
            if(temp < 0){
                temp = nums[i];   
            }
            else{ // temp>=0
                temp += nums[i];
            }
            if(temp > max) {
                max = temp;
            }
        }
        return max;
    }
};

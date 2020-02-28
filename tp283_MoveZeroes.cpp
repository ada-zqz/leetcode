class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0, len = nums.size();
        for(int i = 0; i < len; i++) {
            if(nums[i] == 0) count++;
            else {
                nums[i - count] = nums[i];
            }
        }
        for(int i = len - count; i < len; i++) nums[i] = 0;
    }
};

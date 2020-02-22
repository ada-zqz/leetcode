class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dup = 0; //重复的次数
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1])
                dup++;
            else
                nums[i - dup] = nums[i];
        }
        return nums.size() - dup;
    }
};

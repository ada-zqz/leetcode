class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2, 0);
        for(int i = 0; i < nums.size(); i++) {
            res[1] ^= (i + 1) ^ abs(nums[i]);
            if(nums[abs(nums[i]) - 1] < 0) {
                // 出现两次
                res[0] = abs(nums[i]);
            }
            else {
                // idx处设置为负数
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }
        // res[1] = 重复的数^少的数
        res[1] ^= res[0];
        return res;
    }
};

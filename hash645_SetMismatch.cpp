class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // 第一个方法 hash table
        // 第二个方法 xor
        // vector<int> res(2, 0);
        // for(int i = 0; i < nums.size(); i++) {
        //     res[1] ^= (i + 1) ^ abs(nums[i]);
        //     if(nums[abs(nums[i]) - 1] < 0) {
        //         // 出现两次，也可以额外设数组记录出现次数
        //         res[0] = abs(nums[i]);
        //     }
        //     else {
        //         // idx处设置为负数
        //         nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        //     }
        // }
        // // res[1] = 重复的数^少的数
        // res[1] ^= res[0];
        // return res;
        
        //第三个方法 交换到合适的位置
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] != nums[nums[i] - 1]) swap(nums[i], nums[nums[i] - 1]);
            
        }
        vector<int> res(2);
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1) {
                res[0] = nums[i];
                res[1] = i + 1;
                break;
            }
        }
        return res;
    }
};

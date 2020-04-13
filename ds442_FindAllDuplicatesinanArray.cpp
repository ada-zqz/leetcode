class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int m = abs(nums[i]) - 1;
            if(nums[m] < 0) {     //第二次出现
                res.push_back(m + 1);
            }
            nums[m] = - nums[m];  //m + 1出现一次，m + 1的位置处为负数 
        }
        return res;
    }
};

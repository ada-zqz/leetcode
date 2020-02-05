class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());   // 排序 1,1,2正确  1,2,2不正确
        dfs(0, nums, res);
        return res;
    }
    void dfs(int begin, vector<int>& nums, vector<vector<int>>& res) {
        if(begin == nums.size()) {
            res.push_back(nums);
            return;
        }
        
        for(int i = begin; i < nums.size(); i++) {
            // 除了原序列，其他的，数字相等不交换
            // 前面交换过相等数字不交换(后面会产生重复)
            // 比如[1,2,2], 如果第一个数字为2的序列已经考虑了，不能再加一个2开头的序列
            bool change = true;
            if(i > begin) {
                for(int j = begin; j < i; j++) {
                    if(nums[i] == nums[j]) {
                        change = false;
                        break;
                    }
                }
            }
            if(change) {
                swap(nums[begin], nums[i]);     //比如，nums[0]依次出现nums中的各个数字
                dfs(begin + 1, nums, res);      //位置begin确定了，遍历begin+1的各种可能
                swap(nums[begin], nums[i]);     //复原
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        dfs(0, nums, res);
        return res;
    }
    void dfs(int begin, vector<int>& nums, vector<vector<int>>& res) {
        if(begin == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); i++) {
            swap(nums[begin], nums[i]);
            dfs(begin + 1, nums, res);
            swap(nums[begin], nums[i]);
        }
    }
};

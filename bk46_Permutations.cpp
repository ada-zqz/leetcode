class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), 0); //nums[i]是否已经使用过
        vector<int> pm;
        
        dfs(pm, used, nums, res);
        return res;
    }
    void dfs(vector<int> pm, vector<bool> used, vector<int>& nums, vector<vector<int>>& res) {
        if(pm.size() == nums.size()) {
            res.push_back(pm);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(!used[i]) {
                pm.push_back(nums[i]);
                used[i] = true;
                dfs(pm, used, nums, res);
                pm.pop_back();
                used[i] = false;
            }
        }
    }
};

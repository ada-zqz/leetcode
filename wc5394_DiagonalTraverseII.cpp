class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        int n = nums.size();
        map<int, vector<int>> mp; //对角线上元素i+j相等
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < nums[i].size(); j++) {
                mp[i + j].push_back(nums[i][j]);  // 相同i+j，从j小的开始排序
            }
        }
        for(auto m: mp) {
            for(auto x: m.second) res.push_back(x);
        }
        return res;
    }
};

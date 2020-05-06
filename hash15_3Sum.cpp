class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 3 || 3 * nums[0] > 0 || 3 * nums[n - 1] < 0) return res;
        
        unordered_map<int, set<pair<int, int>>> mp;  //sum, (i,j)
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int sm = nums[i] + nums[j];
                mp[sm].insert({i, j});
            }
        }
        set<vector<int>> ans;
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;  //前一个i已经包含了
            if(mp.find(-nums[i]) != mp.end()) {
                auto st = mp[-nums[i]];
                for(auto s: st) {
                    if(s.first > i) 
                        ans.insert(vector<int>{nums[i], nums[s.first], nums[s.second]});
                }
            }
        }
        for(auto v: ans) res.push_back(v);
        return res;
    }
};

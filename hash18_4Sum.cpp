class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n == 0 || 4 * nums[0] > target || 4 * nums[n - 1] < target) return res;
        // 先算出两两相加的值
        unordered_map<int, set<pair<int, int>>> mp;  //sum, (i,j)
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                mp[nums[i] + nums[j]].insert({i, j});
            }
        }
        set<vector<int>> ans;
        vector<int> v(4);
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                int cd = nums[i] + nums[j];
                if(mp.find(target - cd) != mp.end()) {
                    auto st = mp[target - cd];
                    for(auto s: st) {
                        // index不重复
                        if(s.first > i && s.first != j && s.second != j) {
                            v = vector<int>{nums[i], nums[j], nums[s.first], nums[s.second]};          
                            sort(v.begin(), v.end());
                            // 最终结果不重复
                            ans.insert(v);
                        }
                                          
                    }
                }
            }
        }
        for(auto s: ans) res.push_back(s);
        return res;
    }
};

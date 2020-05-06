class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int, set<pair<int, int>>> mp;  //sum, (i,j)
        int n = nums.size();
        // 先算出两两相加的值
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
                            // 值不重复
                            sort(v.begin(), v.end());
                            ans.insert(v);
                        }
                                          
                    }
                }
            }
        }
        vector<vector<int>> res;
        for(auto s: ans) res.push_back(s);
        return res;
    }
};

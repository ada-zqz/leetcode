class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto n: nums) mp[n]++;  //(key, value): (num, count)
        
        vector<vector<int>> count(nums.size() + 1); //count: num
        for(auto m: mp) count[m.second].push_back(m.first);
        
        vector<int> res;
        for(int i = nums.size(); i >= 1 && res.size() < k; i--) {
            if(count[i].size() > 0) { //count[i].size() > 0 放到上一行判断出错
                for(int j: count[i]) {
                    res.push_back(j);
                    if(res.size() == k) break;
                }
            }
            
        }
        return res;        
    }
};

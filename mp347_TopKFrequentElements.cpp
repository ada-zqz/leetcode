class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto n: nums) mp[n]++;  //(key, value): (num, count)
        
        priority_queue<pair<int, int>> pq; //(count, num);
        for(auto m: mp) pq.push(make_pair(m.second, m.first));        
        
        vector<int> res;
        while(res.size() < k) {
            pair<int, int> p = pq.top();
            pq.pop();
            res.push_back(p.second);
        }
        return res;        
    }
};

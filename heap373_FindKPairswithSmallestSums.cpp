class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        set<pair<int, vector<int>>> mp; // sm, (i, j) (nums[i], nums[j])
        vector<int> ln(2);
        ln[0] = nums1.size();
        ln[1] = nums2.size();
        if(!ln[0] or !ln[1]) return res;
        mp.insert({nums1[0] + nums2[0], vector<int>(2, 0)});
        k = min(ln[0] * ln[1], k);
        while(res.size() < k) {
            auto p = *mp.begin();
            mp.erase(mp.begin());
            res.push_back(vector<int>{nums1[p.second[0]], nums2[p.second[1]]});
            for(int i = 0; i < 2; i++) {
                if(p.second[i] < ln[i] - 1) {
                    auto cp = p.second;
                    cp[i]++;    
                    mp.insert({nums1[cp[0]] + nums2[cp[1]], cp});
                }
            }
        }
        return res;
    }
};

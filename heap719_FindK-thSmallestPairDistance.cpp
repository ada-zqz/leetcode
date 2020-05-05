class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        set<pair<int, vector<int>>> mp; // diff, [i, j]
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 1; i++) 
            mp.insert({nums[i + 1] - nums[i], vector<int>{i, i + 1}});
        int id = 0;
        auto p = *mp.begin();
        while(id < k) {
            p = *mp.begin();
            mp.erase(mp.begin());
            id++;
            if(p.second[1] < n - 1) {
                auto cp = p.second;
                cp[1]++;
                mp.insert({nums[cp[1]] - nums[cp[0]], cp});
            }
        }
        return p.first;
    }
};

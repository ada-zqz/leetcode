class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, pair<int, int>> mp;
        
        for(int n: nums) {
            auto it = mp.find(n);
            if(it == mp.end()) mp[n] = pair<int, int>(n, 1);
            else {
                it->second.second++;
                if(it->second.second > len / 2) {
                    return it->first;
                }
            }
        }
        return nums[0];
    }
};

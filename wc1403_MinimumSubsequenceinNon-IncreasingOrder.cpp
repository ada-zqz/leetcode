class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int sm = 0;
        for(auto i: nums) sm += i;
        vector<int> res;
        int pre = 0;
        for(auto i: nums) {
            pre += i;
            res.push_back(i);
            if(pre > sm - pre) {
                break;
            }
        }
        return res;
    }
};

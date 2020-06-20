class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) swap(nums1, nums2);
        unordered_map<int, int> mp;
        for(auto i: nums1) mp[i]++;
        vector<int> res;
        for(auto i: nums2) {
            if(mp.find(i) != mp.end() && mp[i]-- > 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};

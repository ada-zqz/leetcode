class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;   //sum, fre
        vector<int> sm(nums.size());  //sum [0, i]
        int res = 0;
        sm[0] = nums[0];
        mp.insert({sm[0], 1});
        for(int i = 1; i < nums.size(); i++) {
            sm[i] = sm[i - 1] + nums[i];
            if(mp.find(sm[i]) == mp.end()) mp.insert({sm[i], 1});
            else mp[sm[i]]++;
        }
        res = mp.find(k) == mp.end() ? res : res + mp[k];
        for(int i = 1; i < nums.size(); i++) {
            mp[sm[i - 1]]--;  //不应该再利用，所以减1  [-1, -1, 1], 0  output = 1 not 3
            // [i, j] sum = k  ==  [0, j] sum = k + sm[i - 1]
            int knew = k + sm[i - 1];
            res = mp.find(knew) == mp.end() ? res : res + mp[knew];
        }
        return res;
    }
};

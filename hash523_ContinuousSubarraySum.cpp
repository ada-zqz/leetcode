class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return false;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == 0 && nums[i + 1] == 0) return true; // [0, 0] 0
        }
        if(k == 0) {
            return false; // [0] [1, 2] 0
        }
        k = abs(k);
        
        unordered_map<int, int> mp;
        vector<int> sm(n + 1, 0);
        for(int i = 0; i < n; i++) {
            sm[i + 1] = sm[i] + nums[i];
            int tmp = sm[i + 1] % k;
            if(mp.find(tmp) == mp.end()) {
                if(tmp == 0 && nums[i] < k && nums[i] > 0) return true; // [1, 1] 2 
                // [0,1,0,3,0,4,0,4,0] 5
                mp.insert({tmp, i});
            }
            else {
                if(i - mp[tmp] > 1 && nums[i] != 0) return true;  //[1,5,5] 5
                if(tmp == 0 && i - mp[tmp] == 1) return true; //[0, 5] 5
            }
        }
        return false;
    }
};

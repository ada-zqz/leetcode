class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> mp; //前一个数，到前一个数为止的个数
        int res = 1;
        for(auto a: arr) {
            if(mp.find(a - difference) == mp.end()) {
                mp[a] = 1;
            }
            else {
                mp[a] = mp[a - difference] + 1;
                res = max(res, mp[a]);
            }
        }
        return res;
    }
};

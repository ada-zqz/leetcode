class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> mp; //sm, count
        for(auto a: A) {
            for(auto b: B) {
                mp[a + b]++;
            }
        }
        int res = 0;
        for(auto c: C) {
            for(auto d: D) {
                if(mp.find(-c - d) != mp.end()) {
                    res += mp[-c-d];
                }
            }
        }
        return res;
    }
};

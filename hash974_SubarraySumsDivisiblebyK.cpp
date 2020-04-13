class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        int res = 0;
        unordered_map<int, int> mp;
        mp.insert({0, 0});
        vector<int> sm(n + 1, 0);
        for(int i = 0; i < n; i++) {
            sm[i + 1] = sm[i] + A[i];
            int mod = (sm[i + 1] % K + K) % K; //开始mod会有负数
            if(mp.find(mod) == mp.end()) mp.insert({mod, 1});
            else mp[mod]++;
        }
        res += mp[0];
        for(int i = 1; i < n; i++) {
            int modnew = (sm[i] % K + K) % K;
            mp[modnew]--;
            res += mp[modnew];
        }
        return res;
    }
};

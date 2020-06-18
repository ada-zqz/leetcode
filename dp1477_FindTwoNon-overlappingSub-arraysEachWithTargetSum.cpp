class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp1 = findsub(arr, target); //0-i的子序列中的最短长度
        reverse(arr.begin(), arr.end());
        vector<int> dp2 = findsub(arr, target); //序列倒置后0-i的子序列中的最短长度
        
        int vmin = 0x3f3f3f;
        for(int i = 0; i < n - 1; i++) {
            vmin = min(vmin, dp1[i] + dp2[n - i - 2]); //不overlap的两个子序列
        }
        return vmin >= 0x3f3f3f ? -1 : vmin;
    }
    vector<int> findsub(vector<int>& v, int & t) {
        int n = v.size();
        vector<int> dp(n, 0x3f3f3f);
        vector<int> sm(n, 0);
        unordered_map<int, int> mp; //sm, index
        mp[0] = -1;  //用于sm[i] == target
        for(int i = 0; i < n; i++) {
            sm[i] = i == 0 ? v[i] : sm[i - 1] + v[i];
            if(mp.find(sm[i] - t) != mp.end()) {
                // 0-i: sm[i]; i+1-j:target; 0-j:sm[j]
                dp[i] = min(dp[i], i - mp[sm[i] - t]);
            }
            mp[sm[i]] = i; //之前有一样的和sm[i]，也更新为i，求最短距离
            if(i > 0) dp[i] = min(dp[i], dp[i - 1]);
        }
        return dp;
    }
};

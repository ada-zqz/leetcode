class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k > n) return false;
        if(k == n) return true;
        
        vector<int> dp(26, 0);
        for(auto c: s) dp[c - 'a']++;
        int odd = 0;
        for(auto i: dp) {
            if(i % 2 == 1) odd++;
        }
        if(odd <= k) return true;
        return false;
    }
};

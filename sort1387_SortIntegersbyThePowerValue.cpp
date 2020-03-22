class Solution {
public:
    int getKth(int lo, int hi, int k) {
        static vector<int> dp(1001, -1);
        dp[1] = 0;
        vector<pair<int, int>> st(hi - lo + 1, pair<int, int>());
        for(int i = lo; i <= hi; i++) {
            st[i - lo] = pair<int, int>(findsteps(i, dp), i);
        }
        stable_sort(st.begin(), st.end());
        return st[k - 1].second;
    }
    
    int findsteps(int v, vector<int> & dp) {
        if(v < 1001 && dp[v] != -1) return dp[v];
        int ans;
        if(v % 2 == 0) {
            ans = 1 + findsteps(v / 2, dp);
        }
        else {
            ans = 1 + findsteps(3 * v + 1, dp);
        }
        if(v < 1001) dp[v] = ans;
        return ans;
    }
};

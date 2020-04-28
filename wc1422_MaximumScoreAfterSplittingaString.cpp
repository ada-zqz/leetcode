class Solution {
public:
    int maxScore(string s) {
        int res = 0;
        int n = s.size();
        vector<int> dp1(n + 1, 0);
        vector<int> dp2(n + 1, 0);
        for(int i = 1; i < n; i++) {
            if(s[i - 1] == '0') {
                dp1[i] = dp1[i - 1] + 1;
            }
            else dp1[i] = dp1[i - 1];
            if(s[n - i] == '1') {
                dp2[n - i] = dp2[n - i + 1] + 1;
            }
            else dp2[n - i] = dp2[n - i + 1];
        }
        for(int i = 1; i < n; i++) {
            res = max(res, dp1[i] + dp2[i]);
        }
        return res;
    }
};

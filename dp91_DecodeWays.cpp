class Solution {
public:
    int numDecodings(string s) {
        int dp, dp1, dp2, m, n;
        if(s.size() == 1) {
            if(s == "0") {return 0;}
            return 1;
        }
        if(s[0] - '0' == 0) {return 0;}
        for(int i = 1; i < s.size(); i++) {
            m = s[i] - '0';
            n = s[i - 1] - '0'; 
            if(m == 0 && (n > 2 || n == 0)) {return 0;}
            if(i > 1) {
                if(m == 0) {
                    dp = dp2;
                    dp2 = dp1;
                    dp1 = dp;
                }
                else {
                    if((n == 0) || (n > 2) || ((n == 2) && (m > 6))) {
                        dp = dp1;
                        dp2 = dp1;
                    }
                    else {
                        dp = dp2 + dp1;
                        dp2 = dp1;
                        dp1 = dp;
                    }
                }
            }
            else {
                if(n > 2 || ((n == 2) && (m > 6)) || m == 0) {
                    dp = 1;
                    dp1 = dp;
                    dp2 = 1;
                }
                else {
                    dp = 2;
                    dp1 = dp;
                    dp2 = 1;
                }
            }
        }
        return dp;
    }
};

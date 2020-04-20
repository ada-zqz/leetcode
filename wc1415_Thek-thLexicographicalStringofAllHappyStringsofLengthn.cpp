class Solution {
public:
    string getHappyString(int n, int k) {
        vector<int> dp(n + 1, 0);
        dp[1] = 3;
        for(int i = 2; i <= n; i++) dp[i] = dp[i - 1] * 2;
        string res = "";
        if(k > dp[n]) return res;
        
        vector<string> next(3);
        next[0] = "a";
        next[1] = "b";
        next[2] = "c";
        int m = n;
        int tmp = dp[n];
        while(n > 0) {
            if(n == m) {
                tmp = tmp / 3;
                if(k <= tmp) {
                    res += "a";
                    next[0] = "b";
                    next[1] = "c";
                }
                else if(k <= 2 * tmp) {
                    res += "b";
                    k -= tmp;
                    next[0] = "a";
                    next[1] = "c";
                }
                else {
                    res += "c";
                    k -= 2 * tmp;
                    next[0] = "a";
                    next[1] = "b";
                }
            }
            else {
                tmp = tmp / 2;
                if(k <= tmp) {
                    res += next[0];
                    if(next[0] == "a") {
                        next[0] = "b";
                        next[1] = "c";
                    }
                    else if(next[0] == "b") {
                        next[0] = "a";
                        next[1] = "c";
                    }
                    else if(next[0] == "c") {
                        next[0] = "a";
                        next[1] = "b";
                    }
                }
                else {
                    res += next[1];
                    if(next[1] == "a") {
                        next[0] = "b";
                        next[1] = "c";
                    }
                    else if(next[1] == "b") {
                        next[0] = "a";
                        next[1] = "c";
                    }
                    else if(next[1] == "c") {
                        next[0] = "a";
                        next[1] = "b";
                    }
                    k -= tmp;
                }
                
            }
            n--;
        }
        return res;
    }
};

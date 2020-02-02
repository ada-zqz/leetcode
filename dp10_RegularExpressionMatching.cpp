class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
        f[0][0] = true;
        
        for(int i = 0; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(p[j - 1] == '*' ) {
                    //e.g., s = "aaa", p = "b*c*a*"
                    f[i][j] = f[i][j - 1] || f[i][j - 2];  //*前一个字符是否可以匹配或者匹配0个
                    if(i > 0 && !f[i][j]) {
                        // *匹配多个字符
                        f[i][j] = f[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.');
                    }
                }
                else if(i > 0 && f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {   
                //前一个可以匹配，当前的字母又相等或者p[j - 1]='.'
                    f[i][j] = true;
                }
            }
        }
        return f[m][n];
    }
};

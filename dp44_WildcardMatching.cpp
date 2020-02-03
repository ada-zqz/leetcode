class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        if(m == 0 && n > 0)
            return false;
        vector<bool> cur(m + 1, false); 
        bool pre, temp;  //dp[i - 1][j - 1]
        cur[0] = true;
        
        for(int i = 0; i <= n; i++) {
            pre = (i <= 1) ? true : false;
            for(int j = 1; j <= m; j++) {
                temp = cur[j];  //没有更新前的值，属于dp[i-1][j]
                if(p[j - 1] == '*') {
                    // '*'匹配0个字符 or 匹配当前字符 or 匹配多个字符
                    cur[j] = cur[j - 1] || cur[j];  // 等式后的cur[j]是i-1对应的值，更新cur
                }
                else if(i > 0 && pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?')) {
                    cur[j] = true;
                }
                else {
                    cur[j] = false;  //为false也要赋值，不然会出错
                }
                pre = temp;  //pre由代表dp[i-1][j-1]变为dp[i-1][j]，之后j++
            }
        }
        return cur[m];
    }
};

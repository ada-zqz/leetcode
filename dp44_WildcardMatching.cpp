class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> pre(m + 1, false), cur(m + 1, false); 
        cur[0] = true;
        
        for(int i = 0; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[j - 1] == '*') {
                    // '*'匹配0个字符 or 匹配当前字符 or 匹配多个字符
                    cur[j] = cur[j - 1] || pre[j]; //pre[j - 1]匹配上，p[j]一定也能匹配
                }
                else if(pre[j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '?')) {
                    cur[j] = true;
                }
            }
            cur.swap(pre);
            cur.assign(cur.size(), false);
            // cout << i << s[i - 1] << pre[i] << endl;
        }
        return pre[m];
    }
};

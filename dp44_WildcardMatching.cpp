class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        int i = 0, j = 0, smatch_pos, ptomatch_pos = -1;
        
        while(i < n) {
            if(j < m && (s[i] == p[j] || p[j] == '?')) {
                // j<n是类似出现abcd,ab的情况
                i++;
                j++;
            }
            else if(j < m && p[j] == '*') {
                //smathch_pos可以用*匹配
                //但是先不匹配，而是用p[j+1]看是否匹配s[i]，匹配不成功再换p[j+1]匹配s[i+1]
                smatch_pos = i; 
                ptomatch_pos = j++;
            }
            else if(ptomatch_pos >= 0) {
                //匹配不成功再换'*'后的p[j+1]匹配s[i+1]
                i = ++smatch_pos;
                j = ptomatch_pos + 1;
            }
            else return false;
        }
        while(j < m && p[j] == '*') j++;
        return j == m;
    }
};

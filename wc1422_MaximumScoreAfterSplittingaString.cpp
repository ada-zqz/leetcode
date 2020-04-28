class Solution {
public:
    int maxScore(string s) {
        int c0 = 0, c1 = 0, ans = 0;
        for(auto c: s) c1 += c == '1';
        for(int i = 0; i + 1 < s.size(); ++i)
        {
            c1 -= s[i] == '1';
            c0 += s[i] == '0';
            ans = max(ans, c0 + c1);
        }
        return ans;
    }
};

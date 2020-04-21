class Solution {
public:
    string reformat(string s) {
        string res1;
        string res2;
        string res;
        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) res1 += s[i];
            else res2 += s[i];
        }
        int r = res1.size() - res2.size();
        if(abs(r) > 1) return res;
        if(r < 0) swap(res1, res2);
        int i;
        for(i = 0; i < s.size(); i++) {
            if(i % 2 == 0) res += res1[i / 2];
            else res += res2[i / 2];
        }
        return res;
    }
};

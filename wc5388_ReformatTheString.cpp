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
        for(i = 0; i < res1.size() - 1; i++) {
            res += res1[i];
            res += res2[i];
        }
        if(r == 0) {
            res += res1[i];
            res += res2[i];
        }
        else {
            res += res1[i];
        }
        return res;
    }
};

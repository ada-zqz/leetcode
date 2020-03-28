class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size() == 0) return t[0];
        int res = s[0] - 'a';
        for(int i = 1; i < s.size(); i++) {
            res ^= s[i] - 'a';
        }
        for(int i = 0; i < t.size(); i++) {
            res ^= t[i] - 'a';
        }
        return 'a' + res;
    }
};

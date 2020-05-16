class Solution {
public:
    int maxPower(string s) {
        int res = 1;
        int cnt = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i - 1]) {
                cnt++;
                res = max(res, cnt);
            }
            else {
                cnt = 1;
            }
        }
        return res;
    }
};

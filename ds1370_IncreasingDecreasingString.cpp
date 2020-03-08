class Solution {
public:
    string sortString(string s) {
        string res = "";
        int ns = s.size();
        vector<int> cs(26, 0);
        for(auto c: s) cs[c - 'a']++;
        
        int m = 0;
        while(m < ns) {
            for(int i = 0; i < 26; i++) {
                if(cs[i] > 0) {
                    cs[i]--;
                    res += (char)('a' + i);
                    m++;
                }
            }
            for(int i = 25; i >= 0; i--) {
                if(cs[i] > 0) {
                    cs[i]--;
                    res += (char)('a' + i);
                    m++;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        unordered_map<char, int> mp;
        for(int i = 0; i < s1.size(); i++) {
            // 包含的字符是否相等 
            mp[s1[i]]++;
            mp[s2[i]]--;
        }
        for(auto m: mp) {
            if(m.second != 0) return false;
        }
        for(int i = 1; i <= s1.size() - 1; i++) {
            // 子树是否scramble
            if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
            if(isScramble(s1.substr(0, i), s2.substr(s1.size() - i)) && isScramble(s1.substr(i), s2.substr(0, s1.size() - i))) return true;
        }
        return false;
    }
};

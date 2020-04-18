class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(char m: magazine) {
            if(mp.find(m) == mp.end()) mp.insert({m, 1});
            else mp[m]++;
        }
        for(char r: ransomNote) {
            if(mp.find(r) == mp.end() || mp[r] == 0) return false;
            else mp[r]--;
        }
        return true;
    }
};

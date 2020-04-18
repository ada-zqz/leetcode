class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ds(26, 0);
        for(char m: magazine) {
            ds[m - 'a']++;
        }
        for(char r: ransomNote) {
            if(ds[r - 'a'] == 0) return false;
            else ds[r - 'a']--;
        }
        return true;
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        // 返回连续的最长回文子串
        int n = s.length();
        if(n < 2 || (n == 2 && s[0] == s[1]))
            return s;
        
        int fs = 0, maxl = 1;
        for(int i = 0; i < n - 1; i++) { 
            judgePal(s, i, i, fs, maxl);
            judgePal(s, i, i + 1, fs, maxl);
            
        }
        return s.substr(fs, maxl);
    }
    void judgePal(string& s, int i, int j, int& fs, int& maxl) { 
        while(i >= 0 && j < s.length() && s[i] == s[j]) {
            i--;
            j++;
        }
        if(j - i - 1 > maxl) {
            maxl = j - i - 1;
            fs = i + 1;
        }
    }
};

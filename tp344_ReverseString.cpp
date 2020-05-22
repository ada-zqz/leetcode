class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) swap(s[l], s[r]);
            l++;
            r--;
            // char t = s[l];
            // s[l] = s[r];
            // s[r] = t;
        }
        return;
    }
};

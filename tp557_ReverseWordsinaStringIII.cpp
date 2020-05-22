class Solution {
public:
    string reverseWords(string s) {
        int i, pre = 0;
        for(i = 0; i < s.size(); i++) {
            if(s[i] == ' ') {
                reverse(s, pre, i - 1);
                pre = i + 1;
            }
        }
        reverse(s, pre, i - 1);
        return s;
    }
    void reverse(string& s, int l, int r) {
        while(l < r) {
            swap(s[l++], s[r--]);
        }
    }
};

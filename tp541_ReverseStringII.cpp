class Solution {
public:
    string reverseStr(string s, int k) {
        // 1 - k, 2k+1 - 3k, ...
        int n = s.size();
        int k2 = 2 * k;
        for(int i = 0; i <= (n - 1) / k2; i++) {
            reverse(s, i * k2, min(i * k2 + k - 1, n - 1));
        }
        return s;
    }
    void reverse(string& s, int l, int r) {
        while(l < r) {
            swap(s[l++], s[r--]);
        }
    }
};

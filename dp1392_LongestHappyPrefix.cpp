class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> next(n);
        next[0] = -1;
        int i = 0, k = -1;
        // 找相等会漏掉，还是要先找next数组
        while(i < n - 1) {
            while(k != -1 && s[i] != s[k])
                k = next[k];
            i++;
            k++;
            next[i] = k;
        }
        // k = next[n - 1];
        while(k != -1 && s[n - 1] != s[k]) {
            k = next[k];
        }
        return s.substr(0, k + 1);
    }
};

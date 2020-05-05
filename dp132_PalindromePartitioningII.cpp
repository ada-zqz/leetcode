class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n + 1);
        for(int i = 0; i <= n; i++) cut[i] = i - 1;
        for(int i = 0; i < n; i++) {
            // 奇数回文
            for(int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++) {
                // j = 1, s[i - 1] = s[i + 1]，s[i-1, i+1]是回文，满足条件j=2
                // 可以一直判断s[i-j, i+j]是不是回文
                // 若是回文，前i+j+1个数的cut[i+j+1] = 1 + cut[i - j]; i=j时，s[0,i+j]是回文，cut=0
                cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j]);
            }
            // 偶数回文
            for(int j = 0; i - j >= 0 && i + j + 1 < n && s[i - j] == s[i + j + 1]; j++) {
                cut[i + j + 2] = min(cut[i + j + 2], 1 + cut[i - j]);
            }
        }
        return cut[n];
    }
};

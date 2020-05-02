class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        if(n == 0) return res;
        vector<string> v;
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        // dp[i][j] whether s[i, j] is a palindrome
        for(int i = 0; i < n; i++) {
            dp[i][i] = true;
            // for(int j = i + 1; j < n; j++) 不行
            // 如果认为i是起点，字符串中间元素dp[i + 1][j - 1]要用到后面没有计算的值
            // i应该认为是终点，字符串考虑的最后一个元素
            for(int j = i - 1; j >= 0; j--) { 
                if(s[i] == s[j] && ((i - j) <= 2 || dp[j + 1][i - 1])) {
                    dp[j][i] = true;
                }
            }
        }
        dfs(0, n, s, v, res, dp);
        return res;
    }
    void dfs(int idx, int & n, string & s, vector<string> & v, 
             vector<vector<string>> & res, vector<vector<bool>> & dp) {
        if(idx == n) {
            res.push_back(v);
            return;
        }
        for(int i = idx; i < n; i++) {
            if(dp[idx][i]) {
                v.push_back(s.substr(idx, i - idx + 1));
                dfs(i + 1, n, s, v, res, dp);
                v.pop_back();  // backtracking
            }
        }
    }
};

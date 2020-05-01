class Solution {
public:
    vector<int> getRow(int rowIndex) {
        static vector<vector<int>> dp(1, (vector<int>(1, 1)));
        if(dp.size() > rowIndex) return dp[rowIndex];  //rowIndex从0开始
        vector<int> v;
        int n = dp.size();
        for(int i = n; i <= rowIndex; i++) {
            v.resize(i + 1);      // 第i+1行有i+1个数字
            v[0] = v[i] = 1;
            for(int j = 1; j < i; j++) {
                v[j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            dp.push_back(v);
        }
        return dp[rowIndex];
    }
};

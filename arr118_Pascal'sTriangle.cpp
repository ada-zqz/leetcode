class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        if(numRows == 0) return dp;
        vector<int> v;
        v.push_back(1);
        dp.push_back(v);
        if(numRows == 1) return dp;
        v.push_back(1);
        dp.push_back(v);
        if(numRows == 2) return dp;
        for(int i = 2; i < numRows; i++) {
            vector<int> v {1};
            for(int j = 0; j < dp[i - 1].size() - 1; j++) {
                v.push_back(dp[i - 1][j] + dp[i - 1][j + 1]);
            }
            v.push_back(1);
            dp.push_back(v);
        }
        return dp;
    }
};

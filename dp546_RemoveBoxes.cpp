class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        if(boxes.empty())
            return 0;
        
        //[i, j]前有连续k个boxes与boxes[i]颜色相同时能获得的最大point（到j为止）s
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        return dfs(0, n - 1, 0, boxes, dp);
    }
    
    int dfs(int i, int j, int k, vector<int>& boxes, vector<vector<vector<int>>>& dp) {
        if(i > j) {
            // dp[i][j][k] = 0; i >= n is possible
            return 0;
        }
        if(dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        if(i == j) {
            dp[i][j][k] = (k + 1) * (k + 1);
            return dp[i][j][k];
        }    
        
        //紧接着boxes[i]有相等的颜色
        int prei = i, prek = k;
        for(; i + 1 <= j && boxes[i] == boxes[i + 1]; i++, k++);
        int out = (k + 1) * (k + 1) + dfs(i + 1, j, 0, boxes, dp);
        
        for(int l = i + 2; l <= j; l++) {
            if(boxes[i] == boxes[l]) {
                out = max(out, dfs(i + 1, l - 1, 0, boxes, dp) + dfs(l, j, k + 1, boxes, dp));
            }
        }
        
        dp[prei][j][prek] = out;
        return out;
    }
        
};

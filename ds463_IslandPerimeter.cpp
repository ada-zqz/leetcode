class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> gd(m + 2, vector<int>(n + 2, 0));
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                gd[i][j] = grid[i - 1][j - 1];
            }
        }
        int res = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(gd[i][j] == 0) continue;
                res += !gd[i][j - 1] + !gd[i][j + 1] + !gd[i - 1][j] + !gd[i + 1][j];
            }
        }
        return res;
    }
};

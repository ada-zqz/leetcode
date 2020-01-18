class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int r = grid.size(), c = grid[0].size();
        int landNum = 0; 
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(grid[i][j] == '1') {
                    landNum++;
                    Dfs(i, j, grid, r, c);
                }
            }
        }
        return landNum;
        
    }
    void Dfs(int i, int j, vector<vector<char>>& grid, int r, int c) {
        if(grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        if(i < r - 1) 
            Dfs(i + 1, j, grid, r, c);
        if(i > 0) 
            Dfs(i - 1, j, grid, r, c);
        if(j < c - 1)
            Dfs(i, j + 1, grid, r, c);
        if(j > 0)
            Dfs(i, j - 1, grid, r, c);
    }
};

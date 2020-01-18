class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        int r = grid.size(), c = grid[0].size();
        int landNum = 0; 
        vector<vector<int>> land(r, vector<int>(c, -1)); 
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(land[i][j] < 0) { //没有被探索过
                    if(grid[i][j] == '1') {
                        landNum += 1;
                        Dfs(i, j, grid, land, landNum, r, c);
                    }
                    else { //'0'
                        land[i][j] = 0;
                    }
                }
                
            }
        }
        return landNum;
        
    }
    void Dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& land, int landNum, int r, int c) {
        if(land[i][j] >= 0) {
            return;
        }
        if(grid[i][j] == '1') {
            land[i][j] = landNum;  
            if(i < r - 1) 
                Dfs(i + 1, j, grid, land, landNum, r, c);
            if(i > 0) 
                Dfs(i - 1, j, grid, land, landNum, r, c);
            if(j < c - 1)
                Dfs(i, j + 1, grid, land, landNum, r, c);
            if(j > 0)
                Dfs(i, j - 1, grid, land, landNum, r, c);
        }
        else {
            land[i][j] = 0;
        }
    }
};

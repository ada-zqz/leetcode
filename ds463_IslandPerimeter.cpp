class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cn = 0, ld = 0;  // cn返回两个land cell连接，ld返回land cell的个数
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    ld++;
                    if(j != 0 && grid[i][j - 1]) cn++;
                    if(i != 0 && grid[i - 1][j]) cn++;
                }
            }
        }
        return 4 * ld - 2 * cn; //每个land cell有4条边，有cn个两两相连的岛屿，减去2*cn条边
    }
};

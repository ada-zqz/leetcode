class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        if(m == 0 || n == 0) return {{}};
        
        // 用M保存求和值
        // 255*9 < 2^12
        // int 32bit  2^31-1
        vector<vector<int>> dir {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int sm = M[i][j];  
                int cnt = 1;
                for(auto d: dir) {
                    int x = i + d[0];
                    int y = j + d[1];
                    if(x < 0 || x >= m || y < 0 || y >= n) continue;
                    cnt++;
                    sm += (M[x][y] & 0xFF); //值在255以内
                }
                M[i][j] += (sm / cnt) << 8;
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                M[i][j] = M[i][j] >> 8;
            }
        }
        return M;
    }
};

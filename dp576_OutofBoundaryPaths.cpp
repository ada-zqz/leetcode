class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if(N < 1)
            return 0;
        
        int np = 0, nowN = 0;
        Dfs(np, m, n, N, nowN, i, j);
        return np;
    }
    void Dfs(int& np, int& m, int& n, int& N, int nowN, int i, int j) {
        if((nowN <= N) && (i < 0 || i >= m || j < 0 || j >= n)) {
            np += 1;
            return;
        }
        if(nowN >= N) {
            return;            
        }
        nowN += 1;
        Dfs(np, m, n, N, nowN, i - 1, j);
        Dfs(np, m, n, N, nowN, i + 1, j);
        Dfs(np, m, n, N, nowN, i, j - 1);
        Dfs(np, m, n, N, nowN, i, j + 1);
    }
};

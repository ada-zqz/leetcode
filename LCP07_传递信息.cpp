class Solution {
    int f[6][11];
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        memset(f, 0, sizeof(f));
        f[0][0]=1;
        for(int i = 0; i < k; i++) {
            for(auto r: relation) f[i + 1][r[1]] += f[i][r[0]];
        }
        return f[k][n-1];
    }
};

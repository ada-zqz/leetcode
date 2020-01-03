int SV[100][100]; // 初始自动为0

class Solution {
public:
    int uniquePaths(int m, int n) {
        return PS(m - 1, n - 1);
    }
    int PS(int i, int j) {
        // printf("%d %d\n", i, j);
        if (j == 0 || i == 0) {
            SV[i][j] = 1;
            return 1;
        }
        if (SV[i - 1][j] == 0) {SV[i - 1][j] = PS(i - 1, j);}
        if (SV[i][j - 1] == 0) {SV[i][j - 1] = PS(i, j - 1);}
        return SV[i - 1][j] + SV[i][j - 1];
    }
};

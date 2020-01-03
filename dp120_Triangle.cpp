#define MIN(a, b) ((a) < (b) ? (a) : (b))

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size() - 1;
        for(int i = 1; i < n + 1; i++) {
            for(int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                    continue;
                }
                if (j == triangle[i].size() - 1) {
                    triangle[i][j] += triangle[i - 1][j-1];
                    continue;
                }
                triangle[i][j] += MIN(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
        for(int j = 1; j < triangle[n].size(); j++) {
            if(triangle[n][j] < triangle[n][0]) {
                triangle[n][0] = triangle[n][j];
            }
        }
        return triangle[n][0];
    }
};

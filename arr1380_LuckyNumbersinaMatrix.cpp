class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        vector<int> rmin(m), rpos(m);
        vector<int> visited(n, 0);
        // 找到每一行的最小值
        for(int i = 0; i < m; i++) {
            rmin[i] = matrix[i][0];
            rpos[i] = 0;
            for(int j = 1; j < n; j++) {
                if(matrix[i][j] < rmin[i]) {
                    rmin[i] = matrix[i][j];
                    rpos[i] = j;
                }
            }
        }
        // 对于每一行的最小值
        for(int i = 0; i < m; i++) {
            // 这一列已经计算过
            if(visited[rpos[i]] == 2) continue;
            // 这一列还没计算过
            visited[rpos[i]] = 1;
            for(int j = 0; j < m; j++) {
                if(rmin[i] < matrix[j][rpos[i]]) {
                    // 不是最大值
                    visited[rpos[i]] = 0;
                    break;
                }
            }
            if(visited[rpos[i]] == 1) {
                visited[rpos[i]] == 2;
                ans.push_back(rmin[i]);
            }
        }
        return ans;
    }
};

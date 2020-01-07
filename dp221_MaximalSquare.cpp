#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define min(a, b, c) MIN(MIN(a, b), c)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size();
        vector<int> cur(n, 0), pre(n, 0);
        int maxs = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!i || !j || matrix[i][j] == '0') { //第1行或者第1列或者本身为0，就等于自身
                    cur[j] = matrix[i][j] - '0';
                }
                else {
                    cur[j] = min(pre[j - 1], pre[j], cur[j - 1]) + 1;
                }
                if(cur[j] > maxs) {
                    maxs = cur[j];
                }
            }
            swap(pre, cur);
        }
        return maxs*maxs;
    }
};

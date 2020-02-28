class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int c = 0, r = n - 1; //第一次和右上角的数比较
        while(c < m && r >= 0) {
            if(target == matrix[c][r]) return true;
            else if(target > matrix[c][r]) c++;
            else r--;
        }
        return false;
    }
};

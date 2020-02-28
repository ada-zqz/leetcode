class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int val = matrix[mid / n][mid % n];
            if(target == val) return true;
            else if(target < val) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        int n = nums.size();
        int m = nums[0].size();
        int jmax = 0, imax = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i].size() - 1 + i > jmax) {
                jmax = nums[i].size() - 1 + i;
                imax = i;
            }
        }
        for(int j = 0; j <= jmax; j++) {
            for(int i = n - 1; i >= 0; i--) {
                if(i <= j) {
                    if(nums[i].size() - 1 < j - i) continue;
                    else res.push_back(nums[i][j - i]);                    
                }
            }
        }
        return res;
    }
};

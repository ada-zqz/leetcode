class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        int n = nums.size();
        int jmax = 0;
        vector<int> vl(n);
        set<int, greater<int>> pbi;
        for(int i = 0; i < n; i++) {
            vl[i] = nums[i].size() - 1;
            if(vl[i] + i > jmax) {
                jmax = vl[i] + i;
            }
            pbi.insert(i);
        }
        // cout << n << " " << jmax << endl;
        for(int j = 0; j <= jmax; j++) {
            for(auto i: pbi) {
                if(i <= j) {
                    if(vl[i] + i < j) pbi.erase(i);
                    else res.push_back(nums[i][j - i]); 
                }
                 
            }
        }
        return res;
    }
};

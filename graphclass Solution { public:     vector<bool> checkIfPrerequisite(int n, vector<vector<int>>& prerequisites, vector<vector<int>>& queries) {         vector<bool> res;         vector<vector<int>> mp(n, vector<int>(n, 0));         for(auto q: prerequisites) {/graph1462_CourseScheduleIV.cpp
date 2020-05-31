class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> res;
        vector<vector<int>> mp(n, vector<int>(n, 0));
        for(auto q: prerequisites) {
            // q[0] 是 q[1]的先修
            mp[q[0]][q[1]] = 1;
            for(int i = 0; i < n; i++) {
                if(i != q[0] && mp[i][q[0]] == 1) mp[i][q[1]] = 1;
            }
        }
        for(auto q: queries) {
            if(mp[q[0]][q[1]]) res.push_back(true);
            else res.push_back(false);
        }
        
        return res;
    }
};

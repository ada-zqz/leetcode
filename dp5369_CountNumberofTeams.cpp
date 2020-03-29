class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        if(n < 3) return 0;
        
        vector<vector<int>> dn(n, vector<int>(4, 0));
        vector<vector<int>> dm(n, vector<int>(4, 0));
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            dn[i][1] = 1;
            dm[n - i - 1][1] = 1;
            for(int j = i - 1; j >= 0; j--) {
                if(rating[i] > rating[j]) {
                    dn[i][2] += dn[j][1];
                    dn[i][3] += dn[j][2];
                }
                if(rating[n - i - 1] > rating[n - j - 1]) {
                    dm[n - i - 1][2] += dm[n - j - 1][1];
                    dm[n - i - 1][3] += dm[n - j - 1][2];
                }
            }
            res += dn[i][3] + dm[n - i -1][3];
        }
        return res;
    }
};

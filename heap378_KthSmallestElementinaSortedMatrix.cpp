class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        set<pair<int, vector<int>>> mp; // num, (i, j)
        mp.insert({matrix[0][0], vector<int>(2, 0)});
        vector<int> res;
        while(res.size() < k) {
            auto p = *mp.begin();
            mp.erase(mp.begin());
            res.push_back(p.first);
            for(int i = p.second[1] + 1; i < n; i++) 
                mp.insert({matrix[p.second[0]][i], vector<int>{p.second[0], i}});
            for(int i = p.second[0] + 1; i < m; i++) 
                mp.insert({matrix[i][p.second[1]], vector<int>{i, p.second[1]}});
        }
        return res[k - 1];
    }
};

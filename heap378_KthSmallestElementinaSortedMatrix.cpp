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
            if(p.second[1] + 1 < n) 
                mp.insert({matrix[p.second[0]][p.second[1] + 1], vector<int>{p.second[0], p.second[1] + 1}});
            if(p.second[0] + 1 < m) 
                mp.insert({matrix[p.second[0] + 1][p.second[1]], vector<int>{p.second[0] + 1, p.second[1]}});
        }
        return res[k - 1];
    }
};

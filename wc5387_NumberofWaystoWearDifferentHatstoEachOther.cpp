class Solution {
public:
    int mod = 1e9 + 7;
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        int res = 0;
        unordered_set<int> choose;
        dfs(0, n, hats, choose, res);
        return res;
    }
    void dfs(int idx, int & n, vector<vector<int>>& hats, unordered_set<int> & choose, int & res) {
        if(idx == n) {
            res++;
            return;
        }
        // 第i个人选帽子
        for(int i = 0; i < hats[idx].size(); i++) {
            if(choose.find(hats[idx][i]) == choose.end()) {
                // 帽子没有选过
                choose.insert(hats[idx][i]);
                dfs(idx + 1, n, hats, choose, res);
                choose.erase(hats[idx][i]);
            }
        }
        return;
    }
};

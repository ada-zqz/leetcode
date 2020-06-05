class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> mp(n);
        // mp[i] = {j, -k} i->j, k->i
        for(auto c: connections) {
            mp[c[0]].push_back(c[1]);
            mp[c[1]].push_back(-c[0]);
        }
        return dfs(mp, vector<int>(n) = {}, 0); // visit的位置给vector<int>(n, false)报错
    }
    int dfs(vector<vector<int>>& mp, vector<int>& visit, int from) {
        int change = 0;
        visit[from] = true;
        for(auto to: mp[from]) {
            if(!visit[abs(to)]) {
                // from->to, to > 0, need change the road
                change += (to > 0) + dfs(mp, visit, abs(to));
            }
        }
        return change;
    }
};

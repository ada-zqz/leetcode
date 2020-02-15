class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> ans(n, -1);
        if(richer.empty()) {
            for(int i = 0; i < n; i++) ans[i] = i;
            return ans;
        }
        
        // all people who definitely have equal to or more money than person i
        vector<vector<int>> larger(n);
        for(auto v: richer) larger[v[1]].push_back(v[0]);
        
        for(int i = 0; i < n; i++) {
            dfs(i, ans, quiet, larger);
        }
        return ans;
    }
    int dfs(int i, vector<int>& ans, vector<int>& quiet, vector<vector<int>>& larger) {
        //返回的是比i钱多（或者自己）的人中most quiet的人
        if(ans[i] >= 0) return ans[i];
        ans[i] = i;
        for(int j: larger[i]) { //j比i有钱
            if(quiet[dfs(j, ans, quiet, larger)] < quiet[ans[i]]) {
                ans[i] = ans[j];
            }
        }
        return ans[i];
    }
};

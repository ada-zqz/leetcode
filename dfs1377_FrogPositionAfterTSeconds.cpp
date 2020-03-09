class Solution {
public:
    double pb = 0;
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> dp(n);
        for(auto v: edges) {
            dp[v[0] - 1].push_back(v[1] - 1);
            dp[v[1] - 1].push_back(v[0] - 1);
        }
        vector<int> visited(n, 0);
        visited[0] = 1;
        target--;
        sub(0, t, target, visited, dp, 1);
        return pb;
    }
    void sub(int now, int t, int target, vector<int>& visited, vector<vector<int>>& dp, double p) {
        //到达节点now的概率为p
        if(t == 0 && now == target) pb = p;
        if(t > 0) {
            int n = dp[now].size();
            vector<int> dpnew;
            for(int i: dp[now]) {
                if(visited[i] == 1) n--;
                else dpnew.push_back(i);
            }
            if(n == 0) {
                //叶子节点
                if(now == target) pb = p;
                return;
            }
            else p = p * 1/(double)n;
            for(int i: dpnew) {
                visited[i] = 1;
                sub(i, t - 1, target, visited, dp, p);        
                visited[i] = 0;
            }
        }
    }
};

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int ap = 0;  
        for(auto h: hasApple) if(h) ap++;
        if(ap == 0 || (ap == 1 && hasApple[0])) return 0;
        //边，没用unordered_map因为dfs中判断next节点更简单
        vector<vector<int>> mp(n);   
        for(auto ed: edges) {
            mp[ed[0]].push_back(ed[1]);
            // mp[ed[1]].push_back(ed[0]);
        }
        // 遍历到ap个苹果，路径乘以2
        return 2 * dfs(0, mp, hasApple);
    }
    int dfs(int from, vector<vector<int>>& mp, vector<bool>& hasApple) {
        if(mp[from].size() == 0) return 0;  // 叶子节点
        int cnt = 0;
        for(int to: mp[from]) {
            int next = dfs(to, mp, hasApple);
            // to有苹果或者（没苹果但是子节点有苹果）
            if(hasApple[to] || next) {
                cnt += 1;
                cnt += next;
            }
            
        }
        return cnt;  // 没有apple了返回0
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto g : prerequisites) {
            graph[g[0]].push_back(g[1]);
        }
        vector<int> visit(numCourses, 0);
        vector<int> path;
        // init: 0, visiting: 1, visited: 2
        for(int i = 0; i < numCourses; i++) {
            if(dfs(i, visit, path, graph)) return {};
        }
        return path;
    }
    
    bool dfs(int i, vector<int>& visit, vector<int> & path, vector<vector<int>>& graph) {
        if(visit[i] == 1) return true;  //有环
        if(visit[i] == 2) return false;
        visit[i] = 1;
        for(auto j: graph[i]) {
            if(dfs(j, visit, path, graph)) return true;
        }
        visit[i] = 2;
        path.push_back(i);
        return false;
    }
};

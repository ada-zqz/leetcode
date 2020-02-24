class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto gp: prerequisites) {
            //[0, 1] 修0之前要修1 0->1 visting0->visting1->visted1->visted0
            graph[gp[0]].push_back(gp[1]);
        }
        vector<int> visit(numCourses, 0);
        //init: 0, visting: 1, visted: 2
        for(int i = 0; i < numCourses; i++) {
            if(dfs(i, visit, graph)) return false;  //有环
        }
        return true;
    }
    bool dfs(int n, vector<int>& visit, vector<vector<int>>& graph) {
        if(visit[n] == 1) return true;  //有环
        if(visit[n] == 2) return false;
        
        visit[n] = 1;  //visting
        for(auto i: graph[n]) {
            //有连接的边
            if(dfs(i, visit, graph)) return true;
        }
        visit[n] = 2;  //所有的先修课程都访问完了
        return false;
    }
};

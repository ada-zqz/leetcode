struct eg{
    int f;
    int t;
    int v;
    int id;
    eg(int from, int to, int value, int idx): f(from), t(to), v(value), id(idx) {}
};
// struct cmp {
//     bool operator()(eg& e1, eg& e2) {
//         return e1.v < e2.v;
//     }
// }
class Solution {
public:
    int parent[105];
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // 用结构体表示边，存储之前的相对位置id（输出要用）
        int ne = edges.size();
        vector<eg> egs;
        for(int i = 0; i < ne; i++) {
            egs.push_back(eg(edges[i][0], edges[i][1], edges[i][2], i));
        }
        // 按边的权重从小到大排序，O(mlgm)
        sort(egs.begin(), egs.end(), [](eg& e1, eg& e2){return e1.v < e2.v;});
        
        // kruskal算法，从短的边开始判断是否已经连通
        // 并查集 query set, union set
        int minp = 0;  // MSL对应的边的和
        int nd = 1;    // MST上初始一个点
        vector<int> visited(ne, 1); // 能用的边
        // 初始化：每个点的根是自己，相同的根表示处于同一个集合
        initparent(n, parent);
        MSL(n, egs, minp, visited, nd);    // O(m)
        // cout << minp << endl;
        
        int newp;
        unordered_set<int> cgs;
        vector<int> cg;
        // find critical edges
        for(int i = 0; i < ne; i++) {
            newp = 0;
            visited[i] = 0;  //模拟删除一条边，判断路径和是否还是最小
            initparent(n, parent);
            nd = 1;
            MSL(n, egs, newp, visited, nd);
            if(newp > minp) {
                cgs.insert(egs[i].id);
                cg.push_back(egs[i].id);
            }
            visited[i] = 1;
        }
        vector<int> pcg;
        // find pseudo-critical edges
        for(int i = 0; i < ne; i++) {
            if(cgs.find(egs[i].id) != cgs.end()) continue; //是critical edge
            visited[i] = 0;  //模拟首先已经加入这一条边，判断路径和是否还是最小
            initparent(n, parent);
            merge(egs[i].t, egs[i].f); //parent[egs[i].t] = egs[i].f;
            newp = egs[i].v;
            nd = 2;
            MSL(n, egs, newp, visited, nd);
            if(newp == minp) pcg.push_back(egs[i].id);  //在某一天MST上
            visited[i] = 1;
        }
        return vector<vector<int>> {cg, pcg};
    }
    
    // 初始化：每个点的根是自己，相同的根表示处于同一个集合
    void initparent(int& n, int *parent) {
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    // MST的路径长度
    void MSL(int& n, vector<eg>& egs, int& minp, vector<int>& visited, int & nd) {
        // int nd = 1; //连起来的点
        // egs已经按边排好序
        for(int i = 0; i < egs.size(); i++) {
            if(visited[i] && !sameroot(egs[i].f, egs[i].t)) {
                // from -> to还没有连通
                minp += egs[i].v;
                merge(egs[i].t, egs[i].f);
                nd++;
            }
        }
        // 判断最后是不是所有点都连通起来了
        if(nd < n) minp = INT_MAX;
    }
    
    // 并查集使用的函数
    int getroot(int& c) {
        if(c != parent[c]) {
            parent[c] = getroot(parent[c]);
        }
        return parent[c];
    }
    void merge(int& x, int& y) {
        int rx = getroot(x), ry = getroot(y);
        parent[rx] = ry;
    }
    bool sameroot(int& x, int& y) {
        return getroot(x) == getroot(y);
    }
 };

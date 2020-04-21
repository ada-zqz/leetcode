class Solution {
public:
    int minJump(vector<int>& jump) {
        // BFS
        int n = jump.size();
        set<pair<int, int>> st; //now, pre
        vector<bool> visited(n, false);
        st.insert({0, 0});
        int step = 0;
        while(!st.empty()) {
            step++;
            set<pair<int, int>> newst;            
            for(auto state: st) {
                int id = state.first;
                int pre = state.second;
                // if(visited[id]) continue;                // 之前访问过
                visited[id] = true;
                int right = id + jump[id];                  // 向右跳
                if(right >= n) return step;
                // 之前没有访问过right
                if(!visited[right]) newst.insert({right, id});   
                if(pre >= id) continue;                     // 之前更新过[0, pre]的值
                for(int i = pre + 1; i < id; i++) {         // 向左跳
                    if(!visited[i]) newst.insert({i, id});
                }
            }
            swap(st, newst);
        }
        return -1;
    }
};

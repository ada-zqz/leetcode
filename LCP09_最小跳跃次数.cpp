class Solution {
public:
    int minJump(vector<int>& jump) {
        // BFS
        int n = jump.size();
        set<int> st;
        vector<bool> visited(n, false);
        st.insert(0);
        int step = 0;
        while(!st.empty()) {
            step++;
            set<int> newst;            
            for(int id: st) {
                visited[id] = true;
                if(id + jump[id] >= n) return step;
                newst.insert(id + jump[id]);
                for(int i = 0; i < id; i++) {
                    if(!visited[i]) newst.insert(i);
                }
            }
            swap(st, newst);
        }
        return -1;
    }
};

class Solution {
public:
    int minJump(vector<int>& jump) {
        // BFS
        int n = jump.size();
        queue<int> st; // now index
        vector<bool> visited(n, false);
        st.push(0);
        int pre = -1;      // [0, pre]已经更新过
        int step = 0;
        while(!st.empty()) {
            step++;
            queue<int> newst;            
            while(!st.empty()) {
                int id = st.front();
                st.pop();
                // if(visited[id]) continue;                // 之前访问过
                visited[id] = true;
                int right = id + jump[id];                  // 向右跳
                if(right >= n) return step;
                // 之前没有访问过right
                if(!visited[right]) newst.push(right);   
                if(pre >= id) continue;                     // 之前更新过[0, pre]的值
                for(int i = pre + 1; i < id; i++) {         // 向左跳
                    if(!visited[i]) newst.push(i);
                }
                pre = id;
            }
            swap(st, newst);
        }
        return -1;
    }
};

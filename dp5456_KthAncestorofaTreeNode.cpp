class TreeAncestor {
public:
    unordered_map<int, vector<int>> mp;
    TreeAncestor(int n, vector<int>& parent) {
        mp.clear();
        for(int i = 0; i < n; i++) {
            mp[i].push_back(parent[i]);
        }
        for(int i = 1; i < n; i++) {
            int p = mp[i][0]; //parent
            while(p != 0) {
                for(auto pp: mp[p]) mp[i].push_back(pp);
                p = mp[i].back();
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(mp[node].size() < k) return -1;
        return mp[node][k - 1];
        // while(k-- > 0) {
        //     node = mp[node];
        //     if(node == -1) return -1;
        // }
        // return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

class TreeAncestor {
public:
    int dp[50005][16]; // 2^10=1024, 2^6=64
    TreeAncestor(int n, vector<int>& parent) {
        //dp[i][j] i->2^j
        for(int i = 0; i < 50005; i++) {
            for(int j = 0; j < 16; j++) {
                dp[i][j] = -1;
            }
        }
        for(int i = 0; i < n; i++) {
            dp[i][0] = parent[i]; //往上跳一步到的节点
        }
        for(int i = 1; i < 16; i++) {
            //2^15=32768
            for(int j = 0; j < n; j++) {
                if(dp[j][i - 1] >= 0) dp[j][i] = dp[dp[j][i - 1]][i - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        while(k > 0) {
            int sp = log2(k);
            node = dp[node][sp];
            if(node == -1) return -1;
            k = k - pow(2, sp); // k = k - (1 << sp);
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

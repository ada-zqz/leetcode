class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        vector<int> P(m);
        for(int i = 1; i <= m; i++) 
           P[i - 1] = i;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int val = queries[i];
            int id = findpos(val, P);
            res.push_back(id);
            tofirst(id, P);
        }
        return res;
    }
    int findpos(int v, vector<int>& P) {
        int n = P.size();
        for(int i = n - 1; i >= 0; i--) {
            if(P[i] == v) return i;
        }
        return -1;
    }
    void tofirst(int id, vector<int>& P) {
        int tmp = P[id];
        for(int i = id; i > 0; i--) P[i] = P[i - 1];
        P[0] = tmp;
    }
};

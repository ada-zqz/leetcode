class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for(int i = 0; i < ops.size(); i++) {
            if(m > ops[i][0]) m = ops[i][0];
            if(n > ops[i][1]) n = ops[i][1];
        }
        return m * n;
    }
};

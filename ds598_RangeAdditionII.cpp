class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minm = m, minn = n;
        for(auto o: ops) {
            if(minm > o[0]) minm = o[0];
            if(minn > o[1]) minn = o[1];
        }
        return minm * minn;
    }
};

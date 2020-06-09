class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minm = m, minn = n;
        for(auto o: ops) {
            minm = min(minm, o[0]);
            minn = min(minn, o[1]);
        }
        return minm * minn;
    }
};

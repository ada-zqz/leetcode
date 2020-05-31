class Solution {
public:
    int MOD = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int res = 0, mh = horizontalCuts[0], mw = verticalCuts[0];
        for(int i = 1; i < horizontalCuts.size(); i++) mh = max(mh, horizontalCuts[i] - horizontalCuts[i - 1]);
        mh = max(mh, h - horizontalCuts[horizontalCuts.size() - 1]);
        for(int i = 1; i < verticalCuts.size(); i++) mw = max(mw, verticalCuts[i] - verticalCuts[i - 1]);
        mw = max(mw, w - verticalCuts[verticalCuts.size() - 1]);
        for(int i = 1; i <= mw; i++) {
            res += mh;
            res %= MOD;
        }
        return res;
    }
};

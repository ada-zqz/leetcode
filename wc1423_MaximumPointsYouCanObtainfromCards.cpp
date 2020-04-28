class Solution {
public:
    int maxScore(vector<int>& p, int k) {
        int su = 0, mx = 0, s = p.size();
        for(int i=0; i<k; ++i) su += p[i];
        mx = max(mx, su);
        for(int i=0; i<k; ++i)
        {
            su -= p[k-i-1];
            su += p[s-i-1];
            mx = max(mx, su);
        }
        return mx;
    }
};

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> sm(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            sm[i] = sm[i - 1] + cardPoints[i - 1];
        }
        int res = 0;
        for(int i = 0; i <= k; i++) {
            res = max(res, sm[i] + sm[n] - sm[n - k + i]);
        }
        return res;
    }
};

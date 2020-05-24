class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        // min + K >= max - K return 0
        // min + K < max - K return max - min - 2 * K
        int vmin = INT_MAX, vmax = INT_MIN;
        for(auto a: A) {
            vmin = min(vmin, a);
            vmax = max(vmax, a);
        }
        int res = vmax - vmin - 2 * K;
        return res > 0 ? res : 0;
    }
};

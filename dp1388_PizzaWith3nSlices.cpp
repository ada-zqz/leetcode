class Solution {
public:
    int ans = 0;
    int maxSizeSlices(vector<int>& slices) {
        sub(slices, 0);
        return ans;
    }
    void sub(vector<int> slices, int pre) {
        int n = slices.size();
        if(n == 0) {
            if(pre > ans) ans = pre;
            return;
        }
        if(n == 3) {
            int m = max(slices[0], slices[1]);
            m = max(m, slices[2]);
            if(pre + m > ans) ans = pre + m;
            return;
        }
        vector<int> tmp(n - 3);
        for(int i = 0; i < n; i++) {
            for(int k = 0; k < n - 3; k++) {
                tmp[k] = slices[(i + 2 + k) % n];
            }
            sub(tmp, slices[i] + pre);
        }
    }
};

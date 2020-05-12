class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int n = A.size();
        double lo = 0, hi = 1;
        int p = 0, q = 1;  // 每次要重置分子p，分母只要大于0就行
        for(int cnt = 0; lo < hi; cnt = 0, p = 0) {
            double m = (lo + hi) / 2;
            // 1/5, 1/3, m, 1/2  行列递增
            // 2/5, 2/3
            // 3/5
            for(int i = 0, j = 1; i < n - 1 && j < n; i++) {
                while(j < n && A[i] > m * A[j]) j++;
                // A[i]/A[j] <= m
                cnt += n - j;
                // 记录分子分母
                if(j < n && p * A[j] < q * A[i]) {
                    // A[i]/A[j]最接近m，第k个值是最接近m的A[i][j]<=m
                    // 若m=2/3，开始p=1,q=3，最后p=2,q=3
                    p = A[i];
                    q = A[j];
                }
            }
            
            if(cnt < K) lo = m;
            else if(cnt > K) hi = m;
            else {
                // cnt == K 因为是素数相除，不会有重复的分数
                // 记录的A[p]/A[q]是接近m的最大值
                break;
                // return vector<int> {p, q};
            }
        }
        return vector<int> {p, q};
    }
};

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m * n;
        // 找到cnt>=k的mid的最小值，那这个值一定在table里
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            int cnt = 0;
            for(int i = 1, j = n; i <= m; i++) {
                while(i * j > mid && j > 0) j--;
                if(j == 0) break;
                cnt += j;
            }
            if(cnt >= k) hi = mid; //mid-1有误，因为等于mid的可能有好几个，导致[lo, mid-1]的cnt<k  
            //[lo, mid, hi], [lo, mid]区间内一定有cnt<=k；若lo=mid，跳出循环
            else lo = mid + 1;
        }
        return lo; 
    }
};

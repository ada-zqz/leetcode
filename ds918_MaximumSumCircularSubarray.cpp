class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        int sm = 0;
        for(int& i: A) sm += i;
        int sm1 = findmax(A, 0, n - 1); //首尾不接起来的最大值{x(sss)x}
        // 如果首尾需要接起来最大，那么找{xx(sss)xx}inside(sss)的最小值,sum-最小值
        // 一种找求和最小值的方法，数组取负，找最大值
        // 之前找单个最小值寻找断点的方法不可取，因为存在相等的最小值
        int sm2 = sm - findmin(A, 0, n - 1);  // sm2 = 0会有问题[-2,-3,-1]
        if(sm2 == 0) return sm1; // A只要有正数，就不会为0；只有0和负数，sm1=0；只有负数，sm1=最大的
        return max(sm1, sm2);
    }
    int findmax(vector<int>& A, int start, int end) {
        int sm = A[start];
        int res = sm;
        for(int i = start + 1; i<= end; i++) {
            if(A[i] > A[i] + sm) {
                // sm < 0
               sm = A[i];
            } 
            else sm += A[i];
            res = max(res, sm);
        }
        return res;
    }
    int findmin(vector<int>& A, int start, int end) {
        int sm = A[start];
        int res = sm;
        for(int i = start + 1; i<= end; i++) {
            if(A[i] < A[i] + sm) {
                // sm > 0
               sm = A[i];
            } 
            else sm += A[i];
            res = min(res, sm);
        }
        return res;
    }
};

/*
int sm2 = sm - findmin(A.begin(), A.end() - 1);
int sm3 = sm - findmin(A.begin() + 1, A.end());
int findmax(vector<int>::iterator p, vector<int>::iterator q) {
        int sm = 0;
        int res = -0x3f3f3f;
        for (auto i = p; i != q; i++) {
            sm += *i;
            res = max(res, sm);
            if (sm < 0) {
                sm = 0;
            }
        }
        return res;
    }
*/

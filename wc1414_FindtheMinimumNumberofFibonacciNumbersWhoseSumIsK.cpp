class Solution {
public:
    int Fib(int n, vector<int> & F) {
        if(F[n] != 0) return F[n];
        F[n] = Fib(n - 1, F) + Fib(n - 2, F);
        return F[n];
    }
    int findMinFibonacciNumbers(int k) {
        vector<int> F(46, 0);
        F[1] = 1;
        F[2] = 1;
        int f = Fib(45, F);
        
        int res = 1;
        int pos = findpos(F, k);
        while(F[pos] < k) {
            res++;
            k = k - F[pos];
            pos = findpos(F, k);
        }
        return res;
    }
    int findpos(vector<int>& F, int val) {
        int n = F.size();
        int l = 0, r = n - 1;
        while(r - l > 1) {
            int mid = (l + r) / 2;
            if(F[mid] == val) return mid;
            if(F[mid] > val) r = mid;
            if(F[mid] < val) l = mid;
        }
        if(F[l] == val) return l;
        if(F[r] == val) return r;
        return l;
    }
};

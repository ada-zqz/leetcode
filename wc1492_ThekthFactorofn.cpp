class Solution {
public:
    int kthFactor(int n, int k) {
        int l = 0;
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) l++;
            if(l == k) return i;
        }
        return -1;
    }
};

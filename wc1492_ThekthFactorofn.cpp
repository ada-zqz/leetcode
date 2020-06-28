class Solution {
public:
    int kthFactor(int n, int k) {
        int d = 1;
        for (; d * d <= n; ++d)
            // 也有牺牲空间，在这一步就把n/k存到数组中，之后直接取出来的
            if (n % d == 0 && --k == 0)
                return d;
        for (d = d - 1; d >= 1; --d) {
            if (d * d != n && n % d == 0 && --k == 0)
                return n / d;
        }
        return -1;
    }
};

class Solution {
public:
    int fib(int N) {
        static vector<int> Fb(35, 0);
        Fb[1] = 1;
        if(N <= 1 || Fb[N]) return Fb[N];
        Fb[N] = fib(N - 1) + fib(N - 2);
        return Fb[N];
    }
};

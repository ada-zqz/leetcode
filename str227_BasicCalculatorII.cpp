class Solution {
public:
    int calculate(string s) {
        stringstream iostr("+" + s);
        char op;
        int n, pre, ans = 0;
        while(iostr >> op >> n) {
            if(op == '+' || op == '-') {
                pre = op == '+' ? n : - n;
                ans += pre;
            }
            else {
                ans -= pre;
                pre = op == '*' ? pre * n : pre / n;
                ans += pre;
            }
        }
        return ans;
    }
};

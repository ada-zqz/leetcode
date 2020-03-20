class Solution {
public:
    int calculate(string s) {
        stringstream iostr("+" + s);
        char op;
        int n, pre, now, ans = 0;
        while(iostr >> op >> n) {
            if(op == '+' || op == '-') {
                pre = op == '+' ? n : - n;
                ans += pre;
            }
            else {
                now = op == '*' ? pre * n : pre / n;
                ans += now - pre;
                pre = now;
            }
        }
        return ans;
    }
};

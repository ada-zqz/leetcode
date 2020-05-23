class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int pre = 0, a , b, c;
        if(num1.size() > num2.size()) swap(num1, num2);
        int n1 = num1.size(), n2 = num2.size(); // n1<=n2
        for(int i = 0; i < n2; i++) {
            if(i < n1) {
                a = num1[n1 - 1 - i] - '0';
                b = num2[n2 - 1 - i] - '0';
                c = a + b + pre;
                pre = c / 10;
                res = (char)((c % 10) + '0') + res;
            }
            else {
                c = pre + num2[n2 - 1 - i] - '0';
                pre = c / 10;
                res = (char)((c % 10) + '0') + res;
            }
        }
        if(pre > 0) res = (char)(pre + '0') + res;
        return res;
    }
};

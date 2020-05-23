class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        if(num1.size() < num2.size()) swap(num1, num2);
        vector<string> ms;
        for(int i = num2.size() - 1; i >= 0; i--) {
            // 从低位开始存
            string zero(num2.size() - 1 - i, '0');
            string s = sgmult(num1, num2[i]) + zero;
            ms.push_back(s);
        }
        string res = adds(ms);
        return res;
    }
    string sgmult(string& s1, char& s) {
        // "123" * "4"
        string res;
        int c = s - '0';
        int pre = 0;
        for(int i = s1.size() - 1; i >= 0; i--) {
            int a = s1[i] - '0';
            int b = a * c + pre;
            pre = b / 10;
            
            res = (char)((b % 10) + '0') + res;
        }
        if(pre > 0) res = (char)(pre + '0') + res;
        return res;
    }
    string adds(vector<string>& ms) {
        string pre = ms[0];
        for(int i = 1; i < ms.size(); i++) {
            pre = add(pre, ms[i]);
        }
        return pre;
    }
    string add(string&s1, string& s2) {
        string res;
        int pre = 0, a , b, c;
        int n1 = s1.size(), n2 = s2.size(); // n1<=n2
        for(int i = 0; i < n2; i++) {
            if(i < n1) {
                a = s1[n1 - 1 - i] - '0';
                b = s2[n2 - 1 - i] - '0';
                c = a + b + pre;
                pre = c / 10;
                res = (char)((c % 10) + '0') + res;
            }
            else {
                c = pre + s2[n2 - 1 - i] - '0';
                pre = c / 10;
                res = (char)((c % 10) + '0') + res;
            }
        }
        if(pre > 0) res = (char)(pre + '0') + res;
        return res;
    }
};

class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        return sub(s, n);
    }
    int sub(string s, int n) {
        if(n == 1 && s[0] == '1') return 0;
        if(s[n - 1] == '0') return 1 + sub(s.substr(0, n - 1), n - 1);
        string snew = add1(s, n);
        return 1 + sub(snew, snew.size());
    }
    string add1(string s, int n) {
        string snew(n + 1, '0');
        bool add = true;
        for(int i = n - 1; i >= 0; i--) {
            if(add) {
                if(s[i] == '1') snew[i + 1] = '0';
                else {
                    snew[i + 1] = '1';
                    add = false;
                }
            }
            else {
                snew[i + 1] = s[i];
            }
        }
        if(add) {
            snew[0] = '1';
            return snew;
        }
        return snew.substr(1, n);
    }
};

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0) {
            int m = (n - 1) % 26;
            n = (n - 1) / 26;
            res = (char)(m + 'A') + res;
        }
        return res;
    }
};

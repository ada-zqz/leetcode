class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0 || carry) {
            int n1 = i >= 0 ? a[i--] - '0' : 0;
            int n2 = j >= 0 ? b[j--] - '0' : 0;
            int n = n1 + n2 + carry;
            carry = n / 2;
            res = (char)(n % 2 + '0') + res;
        }
        return res;
    }
};

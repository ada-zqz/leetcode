class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        if(n == 1) return res;
        for(int i = 1; i < n; i++) {
            for(int j = i + 1; j <= n; j++) {
                int gcd = _gcd(i, j);
                // string s = to_string(i/gcd) + "/" + to_string(j/gcd); 有重复出现
                if(gcd == 1) {
                    string s = to_string(i) + "/" + to_string(j);
                    res.push_back(s);
                }
            }
        }
        return res;
    }
    int _gcd(int a, int b) {
        // 最大公因子
        // a<b
        while(b % a != 0) {
            b = b % a;
            swap(a, b);
        }
        return a;
    }
};

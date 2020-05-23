class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int k = 1;  //直接当作进位
        vector<int> res;
        int i = digits.size() - 1;
        while(k > 0 || i >= 0) {
            int n = i >= 0 ? k + digits[i--] : k;
            res.push_back(n % 10);
            k = n / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

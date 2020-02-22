class Solution {
public:
    int reverse(int x) {
        // int range [-2^31, 2^31 - 1]
        if(x == INT_MIN) return 0;
        int sign = x < 0 ? -1 : 1;
        x = abs(x);
        int res = 0;
        while(x) {
            if(INT_MAX / 10 < res || (INT_MAX - x % 10) < res * 10)
                return 0;
            res = res * 10 + x % 10;
            x = x / 10;
        } 
        return res*sign;
    }
};

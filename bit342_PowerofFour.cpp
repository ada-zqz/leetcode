class Solution {
public:
    bool isPowerOfFour(int num) {
        //  4^n - 1 = (2^n + 1) * (2^n - 1)
        // (2^n + 1) (2^n) (2^n - 1)三个数中一定有个数是3的倍数
        // 2^n可能是4^n或者2*4^n, 2*4^n - 1 = 2*(4^n - 1)+1，前半部分是3的倍数，加1不是3的倍数
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};

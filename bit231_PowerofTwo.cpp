class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 00001000 && 00000111 = 0
        // 00001010 && 00001001 前一位的1保持不变
        return n > 0 && ((n & (n - 1)) == 0);  //(n & (n - 1) == 0) 少了括号
    }
};

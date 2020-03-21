class Solution {
public:
    int getSum(int a, int b) {
        int c;
        while(b != 0) {
            c = a & b;  // 某一位都为1，用于进位
            a = a ^ b;  // 某一位为1/0，可以直接相加
            b = (unsigned int)c << 1; // 完成进位，如果为0，则完成加法
            // b = (c & 0x7fffffff) << 1; 
        }
        return a;
    }
};

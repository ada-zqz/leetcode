class Solution {
public:
    int hammingWeight(uint32_t n) {
        // 直接调用bitset函数
        // return bitset<32>(n).count();
        int res = 0;
        // 直接计算每一位是否是1
        // for(int i = 0; i < 32; i++) {
        //     res += n & 1;
        //     n = n >> 1;
        // }
        while(n) {
            n &= n - 1;  // 计算一次少一个1，比上面两种方法多4ms...
            res++;
        }
        return res;
    }
};

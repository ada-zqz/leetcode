class Solution {
public:
    int hammingWeight(uint32_t n) {
        // return bitset<32>(n).count();
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res += n & 1;
            n = n >> 1;
        }
        return res;
    }
};

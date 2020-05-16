class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1 = 0, x2 = 0, mask;
        for(int i: nums) {
            x2 ^= x1 & i;       // 都为1的位进位
            x1 ^= i;
            mask = ~(x1 & x2);  // 出现三次，二进制的3: 11; 出现3次mask=0
            x2 &= mask;
            x1 &= mask;
        }
        return x1;
    }
};

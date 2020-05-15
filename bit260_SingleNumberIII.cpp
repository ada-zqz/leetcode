class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tc = 0;
        // accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        for(auto i: nums) tc ^= i;   //tc: 两个出现一次的elements的异或xor，一定有一位为1
        // 负数：正数取反加1，补码
        tc &= -tc;  //tc为1的低位保留了下来，比如010,101+1=110->010
        // 根据为1的低位把nums化为两部分，一部分该低位为1，一部分为0（要求的两个数自然分到不同的部分）
        vector<int> res(2, 0);
        for(auto i: nums) {
            if(i & tc) 
                res[0] ^= i;
            else
                res[1] ^= i;
        }
        return res;
    }
};

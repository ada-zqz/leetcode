class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bt(32, 0);
        // 32位出现多少次1
        for(int a: nums) {
            for(int i = 0; i < 32; i++) {
                int b = a & 1; 
                if(b) bt[i]++;  //i位为1，bt[i]++
                a = a >> 1;
            }
        }
        int res = 0;
        for(int i = 0; i < 32; i++) {
            int b = bt[i] % 3;  //出现3次归0
            res += b << i;
        }
        return res;
    }
};

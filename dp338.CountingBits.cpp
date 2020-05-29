class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        int i = 1, onebit = 1; //onebit: 2^n
        while(i <= num) {
            if(i == onebit) {
                dp[i++] = 1;
                onebit *= 2;  //下次遇到的只有一个1的数
            }
            else {
                // i < onebit
                // 7 = 4 + 3
                for(int j = 1; 2 * j < onebit && i <= num;) {
                    dp[i++] = dp[j++] + 1;
                }
            }
        }
        return dp;
    }
};

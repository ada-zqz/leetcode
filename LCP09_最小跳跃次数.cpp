class Solution {
public:
    int minJump(vector<int>& jump) {
        int n = jump.size();
        vector<int> dp(n, n);
        dp[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            if(i + jump[i] >= n) dp[i] = 1;
            else dp[i] = 1 + dp[i + jump[i]];
            // 借助[i]更新[i+1, n-1]能到达n的最小值
            for(int j = i + 1; j < n && dp[j] >= 1 + dp[i]; j++)    
                dp[j] = 1 + dp[i];
        }
        return dp[0];
    }
};

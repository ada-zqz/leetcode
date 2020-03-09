class Solution {
public:
    int ans = 0;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> dp(n); //subordinates 
        for(int i = 0; i < n; i++) {
            if(manager[i] >= 0) dp[manager[i]].push_back(i);
        }
        sub(headID, manager, informTime, dp, 0);
        return ans;
    }
    
    void sub(int headID, vector<int>& manager, vector<int>& informTime, vector<vector<int>>& dp, int pre) {
        if(ans < pre) ans = pre;
        for(int i: dp[headID]) {
            sub(i, manager, informTime, dp, informTime[headID] + pre);
        }
    }
};

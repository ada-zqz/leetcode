class Solution {
public:
    // 0-1完全背包问题，优化
    string largestNumber(vector<int>& cost, int target) {
        int n = cost.size();
        deque<int> nm;         // 数字，对应的cost各不相同
        unordered_set<int> st; //相同cost只取最大的i
        for(int i = n - 1; i >= 0; i--) { // 保留cost相同的最大数字
            if(st.find(cost[i]) != st.end()) continue;
            st.insert(cost[i]);
            nm.push_front(i);
        }
        n = nm.size();
        // dp[i][j] 前1-i个数字cost和为j的最大字符串
        vector<vector<string>> dp(n + 1, vector<string>(target + 1, ""));
        for(int i = 1; i <= n; i++) {
            // 从小到大取数字
            // string ss = to_string(nm[i - 1]);  //string add(k, ss); 这里有问题，ss只能为char
            char ss = '0' + nm[i - 1] + 1;
            int ct = cost[nm[i - 1]];
            int j; // k<=j/ct中的j需要定义
            for(j = 0; j <= target; j++) {
                if(cmp(dp[i][j], dp[i - 1][j])) dp[i][j] = dp[i - 1][j];  //不取第i个
                // 取第i个可以取target/ct次
                // for(int k = 1; k <= j / ct; k++) {
                //     // 没有下一句，会出现j=target但是实际求和<target的解 "7777"而不是"7772"
                //     if(j - k * ct > 0 && dp[i - 1][j - k * ct] == "") continue; 
                //     string add(k, ss);
                //     string news = add + dp[i - 1][j - k * ct];   //字符从小到大取的
                //     if(cmp(dp[i][j], news)) dp[i][j] = news;     //取j次第i个
                // }
                // 优化
                if(j == ct || (j > ct && dp[i][j - ct] != "")) {
                    // j>ct, dp[i][j-ct]="" 会导致不是实际求和为j
                    string news = ss + dp[i][j - ct];
                    // dp[i][j-w]= max(dp[i-1][j-w],ss+dp[i-1][(j-w)-w],...,(k-1)*s+dp[i-1][j-kw])
                    // news = max(s+dp[i-1][j-w],...,k*s+dp[i-1][j-kw])
                    if(cmp(dp[i][j], news)) dp[i][j] = news;
                }
            }
        }
        if(dp[n][target] == "") return "0";
        return dp[n][target];
    }
    bool cmp(string& a, string& b) {
        if(a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }
};

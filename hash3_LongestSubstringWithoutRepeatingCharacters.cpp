class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        
        int ans = 1;
        unordered_map<char, int> map;
        map[s[0]] = 0;
        vector<int> dp(n);      //记录以i为最后一个字符的子串的第一个位置
        dp[0] = 0;              //第一个数存在的话一定没有重复
        
        for(int i = 1; i < n; i++) {
            if(map.find(s[i]) == map.end()) {
                map[s[i]] = i;  //第一次出现的位置
                ans = max(ans, i - dp[i - 1] + 1);
                dp[i] = dp[i - 1];
            }
            else {
                int j = max(map[s[i]] + 1, dp[i - 1]);
                ans = max(ans, i - j + 1);
                dp[i] = j;
                map[s[i]] = i;  //重复字符最近出现的位置；
            }
        }
        return ans;
    }
};

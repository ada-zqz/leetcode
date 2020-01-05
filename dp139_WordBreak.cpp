class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, 0);
        string wd;
        dp[0] = true;
        // for(int i = 1; i < s.size() + 1; i++) {dp[i] = false;}
        
        for(int i = 0; i < s.size(); i++) {
            if(!dp[i]) {
                continue;
            }
            for(int j = 0; j < wordDict.size(); j++) {
                wd = wordDict[j];
                if(s.substr(i, wd.length()) == wd) {
                    dp[i + wd.length()] = true;
                }
            }
        }
        if(dp[s.size()]) {return true;}
        return false;
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<string> out;
        string temp;
        vector<vector<int>> dp(n + 1);
        vector<bool> tag(n + 1, 0);  //也可以不开这个数组，用dp[i].size<1替代false的判断
        tag[0] = true;
        
        for(int i = 0; i < n; i++) {
            if(!tag[i]) {continue;}
            for(int j = 0; j < wordDict.size(); j++) {
                if(s.substr(i, wordDict[j].length()) == wordDict[j]) {
                    tag[i + wordDict[j].length()] = true;
                    dp[i + wordDict[j].length()].push_back(i);  //存储上一个能匹配的位置起点, [i, i+wordDict[j].length())代表一个单词
                }
            }
        }
        
        if(dp[n].size() == 0) {return out;}
        else {
            printdp(dp, n, s, temp, out);
        }
        return out;
    }
    
    void printdp(vector<vector<int>>&dp, int idx, string& s, string temp, vector<string>& out) {
        int pre;
        for(int i = 0; i < dp[idx].size(); i++) {
            pre = dp[idx][i];
            if(pre == 0) {
                string ftemp = s.substr(pre, idx - pre) + " " + temp;  //直接用temp的话， 每次pre=0时就改动一次，导致结果错误
                out.push_back(ftemp.substr(0, ftemp.size() - 1));
            }
            else {
                printdp(dp, pre, s, s.substr(pre, idx - pre) + " " + temp, out);
            }
        }
    }
};

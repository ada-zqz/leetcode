class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k >= n) return "0";
        
        // stack
        string res;
        int ers = 0;
        for(int i = 0; i < n; i++) {
            while(!res.empty() && res.back() > num[i] && k > 0) {
                res.pop_back();
                k--;
                ers++;
            }
            res.push_back(num[i]);
        }
        if(k > 0) res.erase(n - ers - k, k);

        // 开头的0删除
        int s = 0;
        while (s < res.size() - 1 && res[s] == '0')  s++;
        res.erase(0, s);
        
        return res;
    }
};

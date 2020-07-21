class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k >= n) return "0";
        
        while(k > 0) {
            int i = 0;
            while(i + 1 < n && num[i] <= num[i+1]) i++;
            // 每次删掉比后面数大的数
            num.erase(i, 1);
            k--;
        }
        // 开头的0删除
        int s = 0;
        while(s < num.size() - 1 && num[s] == '0') s++;
        num.erase(0, s);
        
        return num;
    }
};

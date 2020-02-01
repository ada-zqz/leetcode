class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return vector<string>();
        static const vector<string> c = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> res;
        res.push_back("");
        for(int i = 0; i < digits.size(); i++) {
            int n = digits[i] - '0';
            if(c[n] == "") continue;
            vector<string> tmp;
            for(int j = 0; j < res.size(); j++) {
                for(int k = 0; k < c[n].size(); k++) {
                    tmp.push_back(res[j] + c[n][k]);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};

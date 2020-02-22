class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string cp = "";
        for(int i = 0; i < strs[0].size(); i++) {
            for(int j = 1; j < strs.size(); j++) {
                if(strs[0][i] != strs[j][i]) return cp;
            }
            cp = cp.append(strs[0], i, 1); 
        }
        return cp;
    }
};

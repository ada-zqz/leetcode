class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        int n = names.size();
        vector<string> res(n);        
        res[0] = names[0];
        unordered_map<string, int> mp;
        unordered_map<string, int> rs;
        mp[names[0]] = 1;
        rs[names[0]] = 1;
        for(int i = 1; i < n; i++) {
            string s = names[i];
            if(rs.find(s) == rs.end()) {
                //没有在结果里出现过
                res[i] = s;
                rs[s] = 1;
                mp[s] = 1;
            }
            else {
                //在结果里出现过
                if(mp.find(s) != mp.end()) {
                    //在源中也出现过
                    res[i] = s + "(" + to_string(mp[s]++) + ")";
                    while(rs.find(res[i]) != rs.end()) {
                        res[i] = s + "(" + to_string(mp[s]++) + ")";
                    }
                    rs[res[i]] = 1;
                }
                else {
                    // ["kaido","kaido(1)","kaido","kaido(1)","kaido(2)"]
                    // ["kaido","kaido(1)","kaido(2)","kaido(1)(1)","kaido(2)(1)"]
                    mp[s] = 1;
                    res[i] = s + "(" + to_string(mp[s]++) + ")";
                    while(rs.find(res[i]) != rs.end()) {
                        res[i] = s + "(" + to_string(mp[s]++) + ")";
                    }
                    rs[res[i]] = 1;
                }
            }
        }
        return res;
    }
};

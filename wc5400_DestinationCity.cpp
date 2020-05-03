class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> mp;
        unordered_set<string> st;
        for(auto p: paths) {
            mp[p[0]] = p[1];
            st.insert(p[0]);
            st.insert(p[1]);
        }
        for(auto s: st) {
            if(mp.find(s) == mp.end()) return s;
        }
        return "";
    }
};

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        if(s.size() < k) return false;
        for(int i = 0; i <= s.size() - k; i++) {
            st.insert(s.substr(i, k));
        }
        
        int sm = 1;
        for(int i = 1; i <= k; i++) sm *= 2;
        if(st.size() == sm) return true;
        return false;
    }
};

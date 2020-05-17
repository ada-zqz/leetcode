class Solution {
public:
    string arrangeWords(string text) {
        int n = text.size();
        string res, ans;
        text[0] = tolower(text[0]);  
        vector<string> st;
        string s;
        for(int i = 0; i < n; i++) {
            s.push_back(text[i]);
            if(i == n - 1) s.push_back(' ');
            if(i == n - 1 || text[i] == ' ') {
                st.push_back(s);
                s = "";
            }
        }
        sort(st.begin(), st.end(), [](string &a, string &b){  
            return a.size() < b.size();});
        st[0][0] = toupper(st[0][0]);
        for(string s: st) {
            res += s;
        }
        res = res.substr(0, res.size() - 1);
        return res;       
    }
};

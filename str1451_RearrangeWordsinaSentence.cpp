class Solution {
public:
    struct cmp{
        bool operator()(pair<string, int> &a, pair<string, int> &b) {
            // 字符串长度小的在前面，长度相同的保持原来list中的相对位置
            if(a.first.size() != b.first.size()) return a.first.size() < b.first.size();
            return a.second < b.second;
        }
    };
    string arrangeWords(string text) {
        int n = text.size();
        string res;
        text[0] = tolower(text[0]);  
        vector<pair<string, int>> st; // 字符串，原来的相对位置
        string s; // 按空格提取的字符串
        for(int i = 0; i < n; i++) {
            s.push_back(text[i]);
            if(i == n - 1) s.push_back(' ');
            if(i == n - 1 || text[i] == ' ') {
                st.push_back({s, i});
                s = "";
            }
        }
        sort(st.begin(), st.end(), cmp());
        for(auto s: st) {
            res += s.first;
        }
        res[0] = toupper(res[0]);
        res = res.substr(0, res.size() - 1);  // 去掉最后一个数的空格
        return res;       
    }
};

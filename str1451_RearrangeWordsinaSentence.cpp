class Solution {
public:
    // 比较类
    // struct cmp{
    //     bool operator()(pair<string, int> &a, pair<string, int> &b) {
    //         if(a.first.size() != b.first.size()) return a.first.size() < b.first.size();
    //         return a.second < b.second;
    //     }
    // };
    // 外部比较函数，这里static必须加
    static bool cmp(pair<string, int> &a, pair<string, int> &b) {
        if(a.first.size() != b.first.size()) return a.first.size() < b.first.size();
        return a.second < b.second;
    }
    string arrangeWords(string text) {
        int n = text.size();
        string res, ans;
        text[0] = tolower(text[0]);  
        vector<pair<string, int>> st;
        string s;
        for(int i = 0; i < n; i++) {
            s.push_back(text[i]);
            if(i == n - 1) s.push_back(' ');
            if(i == n - 1 || text[i] == ' ') {
                st.push_back({s, i});
                s = "";
            }
        }
        // sort(st.begin(), st.end(), cmp());
        sort(st.begin(), st.end(), cmp);  //不用加()
        for(auto s: st) {
            res += s.first;
        }
        res[0] = toupper(res[0]);
        res = res.substr(0, res.size() - 1);
        return res;       
    }
};

/* 输入
"Jlhvvd wfwnphmxoa qcuucx qsvqskq cqwfypww dyphntfz hkbwx xmwohi qvzegb ubogo sbdfmnyeim tuqppyipb llwzeug hrsaebveez aszqnvruhr xqpqd ipwbapd mlghuuwvec xpefyglstj dkvhhgecd kry"
*/
/* 输出
"Kry hkbwx ubogo xqpqd jlhvvd qcuucx xmwohi qvzegb qsvqskq llwzeug ipwbapd cqwfypww dyphntfz tuqppyipb dkvhhgecd wfwnphmxoa sbdfmnyeim hrsaebveez aszqnvruhr mlghuuwvec xpefyglstj"
*/

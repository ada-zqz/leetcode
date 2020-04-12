class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<pair<int, string>> vm;
        for(string s:  words) {
            vm.push_back({s.size(), s});
        }
        sort(vm.begin(), vm.end());
        vector<string> res;
        for(int i = 0; i < n - 1; i++) {
            for(int j = n - 1; j > i; j--) {
                // cout << vm[i].second << " " << vm[j].second<<endl;
                if(cmp(vm[i].second, vm[j].second)) {
                    // cout << "true" << vm[i].second <<" " <<  vm[j].second<<endl;
                    res.push_back(vm[i].second);
                    break;
                }
            }
        }
        return res;
    }
    bool cmp(string a, string b) {
        int n = a.size(), m = b.size();
        for(int i = 0; i <= m - n; i++) {
            if(b.substr(i, n) == a) return true;
        }
        return false;
    }
};

class WordFilter {
public:
    unordered_map<string, int> mp;
    WordFilter(vector<string>& words) {
        for(int w = 0; w < words.size(); w++) {
            int n = words[w].size();
            for(int i = 0; i <= n; i++) {
                for(int j = 0; j <= n; j++) {
                    string sadd = words[w].substr(0, i) + "#" + words[w].substr(n - j, j);
                    // insert不更新新的weight
                    if(mp.find(sadd) == mp.end()) mp.insert(make_pair(sadd, w));
                    else mp[sadd] = w;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        if(mp.find(prefix + "#" + suffix) == mp.end()) return -1;
        return mp[prefix + "#" + suffix]; 
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

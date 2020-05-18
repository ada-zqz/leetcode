class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<int, unordered_set<string>> mp;  //people: companies
        int n = favoriteCompanies.size();
        for(int i = 0; i < n; i++) {
            for(auto cmpy: favoriteCompanies[i]) {
                mp[i].insert(cmpy);
            }
        }
        vector<int> res;
        bool contain;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                contain = true;
                for(auto m: mp[i]) {
                    if(mp[j].find(m) == mp[j].end()) {
                        contain = false;
                        break;
                    }
                }
                if(contain) break;  // 是其他人的子集
            }
            if(!contain) res.push_back(i);
        }
        
        return res;
    }
};

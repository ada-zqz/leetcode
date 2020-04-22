class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> menu;
        map<int, map<string, int>> mp;
        for(auto order: orders) {
            int tab = stoi(order[1]);
            string food = order[2];
            menu.insert(food);
            mp[tab][food]++;
        }
        
        vector<vector<string>> ans(1 + mp.size());
        ans[0].push_back("Table");
        for(auto s: menu) ans[0].push_back(s);
        int i = 1;
        for(auto m: mp) {
            ans[i].push_back(to_string(m.first));
            for(auto s: menu) {
                ans[i].push_back(to_string(m.second[s]));
            }
            i++;
        }
        return ans;
    }
};

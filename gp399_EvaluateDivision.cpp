class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 存储a/b=v(b/a=1/v)的关系
        // a: a-1, b-v; b: b-1, a-1/v
        unordered_map<string, unordered_map<string, double>> map;
        for(int i = 0; i < equations.size(); i++) {
            string first = equations[i][0];
            string second = equations[i][1];
            if(map.find(first) == map.end()) {
                unordered_map<string, double> m;
                m[first] = 1.;
                map[first] = m;
            }
            if(map.find(second) == map.end()) {
                unordered_map<string, double> m;
                m[second] = 1.;
                map[second] = m;
            }
            map[first][second] = values[i];
            map[second][first] = 1. / values[i];
        }
        //  计算给定c/d的值；算不出返回-1
        vector<double> ans(queries.size());
        unordered_map<string, bool> visited;
        for(int i = 0; i < queries.size(); i++) {
            string first = queries[i][0];
            string second = queries[i][1];
            pair<bool, double> p = findans(first, second, map, visited);
            if(p.first) ans[i] = p.second;
            else ans[i] = -1;
        }
        return ans;
    }
    pair<bool, double> findans(string s1, string s2, unordered_map<string, unordered_map<string, double>>& map, unordered_map<string, bool> visited) {
        // map中不存在key: s1 or s2，不可能有解
        if(map.find(s1) == map.end() || map.find(s2) == map.end()) {
            return pair<bool, double>(false, -1.);
        }
        // map[s1][s2]有值  s1/s2
        unordered_map<string, double> m = map[s1];
        if(m.find(s2) != m.end()) {
            return pair<bool, double>(true, m[s2]);
        }
        // map[s1][s2]不存在，需要求出是否有解，有解的情况更新map并返回
        visited[s1] = true;  // 防止a遍历b时，b遍历回a，无意义的循环
        for(auto it = m.begin(); it != m.end(); ++it) {
            if(visited.find(it->first) == visited.end()) { // 之前没找过的字符串
                visited[it->first] = true;
                pair<bool, double> p = findans(it->first, s2, map, visited);  // 递归
                if(p.first) {
                    //a-c: a-b, b-c
                    map[s1][s2] = p.second * it->second;
                    map[s2][s1] = 1 / p.second / it->second;
                    return pair<bool, double>(true, map[s1][s2]);
                }
            }
        }
        return pair<bool, double>(false, -1.);
    }
};

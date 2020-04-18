class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        unordered_map<int, vector<int>> mp;
        for(auto r: relation) {
            if(mp.find(r[0]) == mp.end()) {
                vector<int> v;
                v.push_back(r[1]);
                mp.insert(pair<int, vector<int>>(r[0], v));
            }
            else mp[r[0]].push_back(r[1]);
        }
        queue<int> now;
        now.push(0);
        int step = 0;
        int res = 0;
        while(!now.empty()) {
            if(step == k) {
                while(!now.empty()) {
                    int pp = now.front();
                    now.pop();
                    // cout << pp << " ";
                    if(pp == n - 1) res++;
                }
                return res;
            }
            step++;
            // if(step > k) break;
            queue<int> next;
            while(!now.empty()){
                int p = now.front();
                now.pop();
                if(mp.find(p) != mp.end()) {
                    for(auto pp: mp[p]) {
                        next.push(pp);
                    }
                }
            }
            swap(now, next);
        }
        return 0;
    }
};

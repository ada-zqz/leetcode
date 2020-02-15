class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        // all people who definitely have equal to or more money than person i
        vector<vector<int>> rclist(n);
        
        // find all people who definitely have equal to or more money than person i
        for(auto v: richer) {
            // [0]: [1]; [1]: [2, 3], ...
            rclist[v[1]].push_back(v[0]);
        }
        for(int i = 0; i < n; i++) {
            if(!rclist[i].empty()) {
                vector<bool> added(n, false);
                queue<int> larger;
                for(int j: rclist[i]) {
                    larger.push(j);
                    added[j] = true;
                }
                replenish(larger, rclist[i], rclist, added);
            }
        }
        
        // find the least quiet person
        vector<int> ans(n);
        for(int i = 0; i < n; i++) {
            int m = quiet[i];
            ans[i] = i;
            if(!rclist[i].empty()) {
                for(int j: rclist[i]) {
                    if(quiet[j] < m) {
                        ans[i] = j;
                        m = quiet[j];
                    }
                }
            }
        }
        return ans;
    }
    
    void replenish(queue<int> larger, vector<int>& append, vector<vector<int>>& rclist, vector<bool>& added) {
        while(!larger.empty()) {
            int i = larger.front();
            larger.pop();
            for(int j: rclist[i]) {
                if(!added[j]) {
                    append.push_back(j);
                    added[j] = true;
                }
                larger.push(j);
            }
        }
    }
};

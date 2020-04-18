class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
        int n = requirements.size();
        int t = increase.size();
        vector<int> res(n, -1);
        for(int i = 0; i < n; i++) {
            if(requirements[i][0] == 0 && requirements[i][1] == 0 && requirements[i][2] == 0) res[i] = 0;
        }
        vector<vector<int>> sm(3, vector<int>(t + 1, 0));
        for(int i = 1; i <= t; i++) {
            for(int j = 0; j < 3; j++) {
                sm[j][i] = sm[j][i - 1] + increase[i - 1][j]; 
            }
        }
        for(int i = 0; i < n; i++) {
            if(res[i] != -1) continue;
            int r1 = findpos(sm[0], requirements[i][0]);
            int r2 = findpos(sm[1], requirements[i][1]);
            int r3 = findpos(sm[2], requirements[i][2]);
            if(r1 == -1 || r2 == -1 || r3 == -1) res[i] = -1;
            else res[i] = max(max(r1, r2), r3);
        }
        return res;
    }
    int findpos(vector<int>& sm, int val) {
        int n = sm.size();
        if(val <= sm[1]) return 1;
        if(val > sm[n - 1]) return -1;
        int l = 1, r = n - 1;
        while(r - l > 1) {
            int mid = (l + r) / 2;
            if(sm[mid] == val) {
                if(sm[mid - 1] < val) return mid;
                while(sm[mid - 1] == val) {
                    mid--;
                }
                return mid;
            }
            if(sm[mid] > val) r = mid;
            if(sm[mid] < val) l = mid;
        }
        if(sm[l] == val) {
            if(sm[l - 1] < val) return l;
            while(sm[l - 1] == val) {
                l--;
            }
            return l;
        }
        return r;
    }
};

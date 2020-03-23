class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> mp;
        for(auto r: reservedSeats) {
            mp[r[0]].push_back(r[1]);
        }
        int ans = 2 * n;
        for(auto m: mp) {
            bool left = true;
            bool right = true;
            bool center = true;
            for(auto v: m.second) {
                if(v >= 2 && v <= 5) left = false;
                if(v >= 6 && v <= 9) right = false;
                if(v >= 4 && v <= 7) center = false;
            }
            if(left && right) continue;
            if(left || right || center) ans -= 1;
            else ans -= 2;
        }
        return ans;
    }
};

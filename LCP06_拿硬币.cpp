class Solution {
public:
    int minCount(vector<int>& coins) {
        int ans = 0;
        for(auto i: coins) ans += i + 1 >> 1;
        return ans;
    }
};

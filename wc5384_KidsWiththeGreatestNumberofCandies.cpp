class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;
        int vmax = INT_MIN;
        for(auto i: candies) vmax = max(vmax, i);
        for(auto i: candies) {
            if(i + extraCandies >= vmax) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};

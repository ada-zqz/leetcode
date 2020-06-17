class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(auto & v: A) {
            reverse(v.begin(), v.end());
            for(auto & i: v) i ^= 1;
        }
        return A;
    }
};

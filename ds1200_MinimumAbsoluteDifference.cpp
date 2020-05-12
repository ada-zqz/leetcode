class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int dmin = 0x3f3f3f;
        int n = arr.size();
        for(int i = 1; i < n; i++) {
            dmin = min(dmin, arr[i] - arr[i - 1]);
        }
        vector<vector<int>> res;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n && (arr[j] - arr[i] == dmin); j++) {
                res.push_back(vector<int>{arr[i], arr[j]});
            }
        }
        return res;
    }
};

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(int v: arr1) {
            bool s = true;
            for(int c: arr2) {
                if(abs(v - c) <= d) {
                    s = false;
                    break;
                }
            }
            if(s) ans++;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int pos = 0;
        int diff = abs(arr[0] - x);
        for(int i = 1; i < n; i++) {
            int d = abs(arr[i] - x);
            if(d < diff) {
                diff = d;
                pos = i;
            }
        }
        deque<int> res; 
        res.push_back(arr[pos]);
        int nl = 1, nr = 1;
        while(res.size() < k) {
            int dr, dl;
            if(pos + nr < n) {
                dr = abs(arr[pos + nr] - x);
            }
            else dr = INT_MAX;
            if(pos - nl >= 0) {
                dl = abs(arr[pos - nl] - x);
            }
            else dl = INT_MAX;
            if(dl <= dr) {
                res.push_front(arr[pos - nl]);
                nl++;
            }
            else {
                res.push_back(arr[pos + nr]);
                nr++;
            }       
        }
        vector<int> ans;
        for(auto i: res) ans.push_back(i);
        return ans;
    }
};

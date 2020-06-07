class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        if(n == 1) return vector<int> {arr[0]};
        vector<int> brr;
        for(auto a: arr) brr.push_back(a);
        sort(arr.begin(), arr.end());
        int mn = (n - 1) / 2;
        int mid = arr[mn];
        auto cmp = [](pair<int, int> u1, pair<int, int> u2) { 
            if(u1.first != u2.first) return u1.first > u2.first; 
            return u1.second < u2.second;     
        };
        multiset<pair<int, int>, decltype(cmp)> mt(cmp);  //val, idx
        for(int i = 0; i < n; i++) {
            mt.insert({abs(brr[i] - mid), i});
        }
        
        vector<int> res(k);
        int i = 0;
        for(auto m: mt) {
            if(i < k) {
                res[i++] = brr[m.second];
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        if(n == 1) return vector<int> {arr[0]};
        sort(arr.begin(), arr.end());
        int mn = (n - 1) / 2;
        int mid = arr[mn];
        vector<int> res;
        auto cmp = [](pair<int, int> u1, pair<int, int> u2) { return u1.first < u2.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({abs(arr[0] - mid), 0});
        pq.push({abs(arr[n - 1] - mid), n - 1});
        while(res.size() < k) {
            auto p = pq.top();
            pq.pop();
            cout<<p.second<<" ";
            res.push_back(arr[p.second]);
            if(p.second > mn) pq.push({abs(arr[p.second - 1] - mid), p.second - 1});
            if(p.second < mn) pq.push({abs(arr[p.second + 1] - mid), p.second + 1});
        }
        return res;
    }
};

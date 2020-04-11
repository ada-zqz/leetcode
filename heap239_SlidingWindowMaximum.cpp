class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int n = nums.size();
        vector<int> res;
        int ans = 1 << 31;
        if(k >= n) {
            for(int i: nums) ans = max(ans, i);
            res.push_back(ans);
            return res;
        }
        for(int i = 0; i < n; i++) {
            pq.push({nums[i], i});
            if(i < k - 1) continue;
            auto mx = pq.top();
            while(mx.second < i - k + 1) {
                pq.pop();
                mx = pq.top();
            }
            res.push_back(mx.first);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        map<int, int> pre; // 第一个数，index
        // set<pair<int, int>> suf; // 第二个数，index
        for(int i = 0; i < n; i++) {
            pre.insert({intervals[i][0], i});
            // suf.insert({intervals[i][1], i});
        }
        vector<int> res(n, -1);
        for(int i = 0; i < n; i++) {
            // intervals[i][1] 是其他的前面数组，即小于该数组的第一个数
            // 前缀找大于等于intervals[i][1] 
            auto itr = pre.upper_bound(intervals[i][1] - 1);
            if(itr != pre.end()) res[i] = itr->second;
        }
        return res;
    }
};

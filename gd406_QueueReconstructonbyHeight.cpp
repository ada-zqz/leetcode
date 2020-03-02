class Solution {
public:
    struct comp {
        bool operator()(const vector<int> & a, const vector<int> & b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
            // 高度大的排在前面，高度相等的，k小的排在前面
        }
    };
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp());
        vector<vector<int>> res;
        for(auto p: people) {
            res.insert(res.begin() + p[1], p);
            //h大的people排好后，h小的people继续排不影响h大的人的相对位置
        }
        return res;
    }
};

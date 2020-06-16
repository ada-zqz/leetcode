class Solution {
public:
    int minDays(vector<int>& by, int m, int k) {
        // 二分法：先给定day，判断合不合适，确定上限，然后不断缩小限制
        int n = by.size();
        if(n < m * k) return -1;
        
        auto v = minmax_element(by.begin(), by.end());
        int l = *v.first, r = *v.second;
        int ok;
        while(l < r) {
            int mid = (l + r) >> 1;
            ok = okm(by, mid, k);
            if(ok >= m) r = mid;
            else l = mid + 1;
        }
//         return okm(by, l, k) >= m ? l : -1;
        return l; //第6行已经判断一定可行，只是时间长短的问题
    }
    int okm(const vector<int>& by, int & mid, int & k) {
        int res = 0, cnt = 0;
        for(auto & b: by) {
            if(b <= mid) cnt++;
            else cnt = 0;
            if(cnt == k) {
                cnt = 0;
                res++;
            }
        }
        return res;
    }
};

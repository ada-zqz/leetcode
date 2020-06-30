class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int res = 0;
        for(int i = 0, cnt = 0; i < A.size() - 1; i++, cnt *= -1) {
            if(A[i] < A[i + 1]) {
                cnt = cnt > 0 ? cnt + 1 : 1;
            }
            else if(A[i] > A[i + 1]) {
                cnt = cnt < 0 ? cnt - 1 : -1;
            }
            else {
                cnt = 0;
            }
            res = max(res, abs(cnt));
        }
        return res + 1;
    }
};

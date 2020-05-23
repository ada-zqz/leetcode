class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        // 直接把K当作进位，而不是先转化为数，再每一位相加
        if(K == 0) return A;
        vector<int> res;
        for(int i = A.size() - 1; i >= 0; i--) {
            int n = A[i] + K;
            res.push_back(n % 10);
            K = n / 10;
        }
        while(K > 0) {
            res.push_back(K % 10);
            K /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

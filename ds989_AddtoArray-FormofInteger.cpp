class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        if(K == 0) return A;
        vector<int> k;
        while(K != 0) {
            // 34 -> [3, 4]
            k.push_back(K % 10);
            K /= 10;
        }
        reverse(k.begin(), k.end());
        if(A.size() < k.size()) swap(A, k);
        int n1 = A.size(), n2 = k.size(); //n1>=n2
        vector<int> res;
        int carry = 0;  //进位
        int num;
        for(int i = 0; i < n1; i++) {
            if(i < n2) {
                num = A[n1 - 1 - i] + k[n2 - 1 - i] + carry;
                carry = num / 10;
                res.push_back(num % 10);
            }
            else {
                num = A[n1 - 1 - i] + carry;
                carry = num / 10;
                res.push_back(num % 10);
            }
        }
        if(carry) res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};

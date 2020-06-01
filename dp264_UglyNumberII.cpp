class Solution {
public:
    int nthUglyNumber(int n) {
        static vector<int> un {1};
        static int i = 0, j = 0, k = 0;
        while(un.size() < n) {
            // 从最小的数的2，3，5倍开始
            un.push_back(min(un[i] * 2, min(un[j] * 3, un[k] * 5)));
            // 1倍的2已经考虑了，要从第二个最小的数开始乘以2
            if(un.back() == un[i] * 2) i++;
            if(un.back() == un[j] * 3) j++;
            if(un.back() == un[k] * 5) k++;
        }
        return un[n - 1];
    }
};

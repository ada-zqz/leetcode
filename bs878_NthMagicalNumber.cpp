typedef long long ll;
class Solution {
public:
    const int MOD = 1e9 + 7;
    int nthMagicalNumber(int N, int A, int B) {
        if(A > B) swap(A, B);  // 保证A<=B
        ll lo = A, hi = (ll)A * N;
        ll mid;  
        int n;
        while(lo <= hi) {  //N=1, A=2, B=3 -> lo=hi
            mid = (lo + hi) / 2;
            if(B % A == 0) {
                n = mid / A;
            }
            else {
                n = (mid / A) + (mid / B) - (mid / (A * B));
            }
            if(n < N) lo = mid + 1;
            else if(n > N) hi = mid - 1;
            else {
                // n == N
                cout << mid;
                while((mid % A) && (mid % B)) {
                    mid -= min(mid % A, mid % B);   
                }
                break;
            }
        }
        return mid % MOD;
    }
};

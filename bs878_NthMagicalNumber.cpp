typedef long long ll;
class Solution {
public:
    const int MOD = 1e9 + 7;
    int gcd(int A, int B) {
        // 最大公约数gcd(greatest common divisor)  gcd(a, b) = gcd(b % a, a) (a<=b)
        while(A > 0) {
            B = B % A;
            swap(A, B);
        }
        return B;
    }
    int nthMagicalNumber(int N, int A, int B) {
        if(A > B) swap(A, B);  // 保证A<=B
        // (A, B)的最大公约数，最小公倍数  (8, 10) 2, 40(而不是80)
        // 先求最大公约数gcd(greatest common divisor)，最小公倍数=A*B/gcd
        int lcm = A * B / gcd(A, B);  // least common multiple
        ll lo = A, hi = (ll)A * N;
        ll mid;  
        int n;
        while(lo <= hi) {  //N=1, A=2, B=3 -> lo=hi
            mid = (lo + hi) / 2;
            if(B % A == 0) {
                n = mid / A;
            }
            else {
                // 10,10,8  (mid=40计算不对40=5*8=4*40)
                // n = (mid / A) + (mid / B) - (mid / (A * B));
                n = (mid / A) + (mid / B) - (mid / lcm);
            }
            if(n < N) lo = mid + 1;
            else if(n > N) hi = mid - 1;
            else {
                // n == N
                while((mid % A) && (mid % B)) {
                    mid -= min(mid % A, mid % B);   
                }
                break;
            }
        }
        return mid % MOD;
    }
};

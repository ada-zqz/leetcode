/*
1 <= n, a, b, c <= 10^9
1 <= a * b * c <= 10^18
*/
typedef long long ll;
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        ll l = 1, r = 2e9;
        ll ab = (ll)(a) * (ll)(b) / gcd((ll)(a), (ll)(b));  //最小公倍数
        ll ac = (ll)(a) * (ll)(c) / gcd((ll)(a), (ll)(c));
        ll bc = (ll)(b) * (ll)(c) / gcd((ll)(b), (ll)(c));
        ll abc = (ll)(a) * bc / gcd((ll)(a), (ll)(bc));     //mid是abc的倍数，多减了一次要加回来
        while(l < r) {
            ll mid = (l + r) / 2;
            ll m = mid / a + mid / b + mid / c - mid / (ab) - mid / (ac) - mid / (bc) + mid / (abc);
            if(m >= n) r = mid;
            else l = mid + 1;
        }
        return l;
    }
    ll gcd(ll a, ll b) {
        //a<b
        //最大公倍数
        while(a > 0) {
            b = b % a;
            swap(a, b);
        }
        return b;
    }
};

struct ug {
    int val;   //现在的数到了val=dp[base]乘以primes[idx]，base依次增大，基数逐渐增加
    int base;  //dp[base]  计算以之前的那个数为基数
    int p;     //固定的，primes[idx]
    ug(int v, int b, int pr): val(v), base(b), p(pr) {}
};
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // heap: O(nlgk)
        if(n == 1) return 1;
        // sort(primes.begin(), primes.end());
        int k = primes.size();
        vector<int> dp;
        dp.push_back(1);
        
        auto cmp = [](ug u1, ug u2) { return u1.val > u2.val; };
        priority_queue<ug, vector<ug>, decltype(cmp)> pq(cmp);
        
        // val = base * primes[i]
        for(int i = 0; i < k; i++) pq.push(ug(primes[i], 0, primes[i]));
        int j = 1;
        while(j < n) {
            ug res = pq.top();
            pq.pop();
            if(res.val > dp[j - 1]) {
                dp.push_back(res.val);
                j++;
            }
            pq.push(ug(dp[res.base + 1] * res.p, res.base + 1, res.p)); // 前一个数已经乘了p，下一个乘以p的是dp[base+1]
        }
        return dp[n - 1];
    }
};


class Solution {
public:
    int MOD = 1e9 + 7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<long long, long long>> p;
        for(int i = 0; i < n; i++) {
            p.push_back(pair<long long, long long>(efficiency[i], speed[i]));
        }
        //efficiency从大到小排
        sort(p.rbegin(), p.rend());        
        
        long long mp = 1 << 31;
        long long sum = 0;
        //k+1个人时speed最小的弹出
        priority_queue<long long, vector<long long>, greater<long long>> q;  
        for(int i = 0; i < n; i++) {
            //q: speed从大到小输出
            q.push(p[i].second);     
            //sum of speed
            sum += p[i].second;          
            //人数多于k时需要剔除某人；包括eff小的工友时，只要k没满，加上eff大的只会增加mp，所以k没满的情况是最终解只能是出现在eff大的工友中
            while(q.size() > k) {
                //k+1中speed的最小值top(); 始终保持不大于k个人的sum
                sum -= q.top();          
                q.pop();
            }
            // at most k，人数可以少于k，因为人数多了efficiency反而下降更快
            mp = max(mp, sum * p[i].first);  //如果包括第i个人，需要用新的eff；最终sum不包括第i个人也没关系，因为此时不会大于mp
        }
        return mp % MOD;
    }
};

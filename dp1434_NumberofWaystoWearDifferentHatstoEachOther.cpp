class Solution {
public:
    // 考虑MOD的加法
    const int MOD = 1e9 + 7;
    int addmod(int & a, int & b) {
        int c = a + b;
        return c % MOD;
    }
    int numberWays(vector<vector<int>>& hats) {
        int n = hats.size();
        // // 每个人可以匹配的帽子用map表示，减少查询时间
        // unordered_map<int, unordered_set<int>> hs;
        // for(int i = 0; i < n; i++) {
        //     for(int h: hats[i]) mp[i].insert(h);
        // }
        // // 直接用bool b[10][41]的数组存也是直接查询
        // bool h[10][41];
        // memset(h, 0, sizeof(h));
        // for(int i = 0; i < n; i++) {
        //     for(int t: hats[i]) h[i][t] = true;
        // }
        // 换成每个帽子能被谁带上
        unordered_map<int, unordered_set<int>> people;
        for(int i = 0; i < n; i++) {
            for(int h: hats[i]) people[h].insert(i);
        } 
        
        // 人选帽子dfs，10个人，每个人40种可能，40全排列
        // 帽子选人，最多40个帽子分配给10个人，40*10*2^10 没加一个帽子给一个人，更新dp
        // hint: dp(peopleMask, idHat) number of ways to wear different hats given a bitmask (people visited) and used hats from 1 to idHat.
        // peopleMask的二进制表达表示n个人戴帽子的状态
        vector<int> pre(1 << n, 0);  //前一个状态，和现在的状态
        vector<int> now(1 << n, 0); 
        pre[0] = 1;
        for(int i = 1; i <= 40; i++) {
            // 帽子不能被人戴上
            if(people.find(i) == people.end()) continue;
            // 第i个帽子可以被戴上
            now = pre;  // 一定要这个，不然会漏掉其他people戴的帽子的情况
            for(int p: people[i]) {
                // 给第p个人戴第i个帽子有多少可能(p从0开始的)
                for(int mask = 0; mask < (1 << n) - 1; mask++) {
                    if((mask & (1 << p)) == 0) {
                        //第p个人现在没戴帽子，戴上i这个帽子，增加(1,...,1)的可能数
                        now[mask | (1 << p)] = addmod(now[mask | (1 << p)], pre[mask]);
                    }                    
                }
            }
            swap(now, pre);
        }
        return pre[(1 << n) - 1];
    }
};

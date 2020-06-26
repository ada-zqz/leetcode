class Solution {
public:
    int minDistance(vector<int>& houses, int K) {
        // houses依次排序好
        sort(houses.begin(), houses.end());
        int n = houses.size();
        vector<int> sm(n + 1, 0);
        for(int i = 0; i < n; i++) sm[i + 1] = sm[i] + houses[i];
        vector<int> dp(n); //目前k（不断添加）个箱子，[0, i]最短的路程
        for(int i = 0; i < n; i++) {
            // 加一个箱子
            dp[i] = dis(sm, 0, i);
        }
        
        for(int k = 2; k <= K; k++) {
            //已经放了k-1个邮箱，新的j从k-1开始
            for(int j = n - 1; j >= k - 1; j--) {
                // 从后往前更新dp
                for(int i = k - 2; i < j; i++) {
                    // [0, i] k-1个邮箱；[i+1, j]放一个邮箱 
                    // 二维的话 dp[j][k] = min(dp[i][k-1] + cal[i + 1, j])
                    dp[j] = min(dp[j], dp[i] + dis(sm, i + 1, j));
                }
            }
        }
        return dp[n - 1];
    }
    
    // [i, j]放一个邮箱的距离
    int dis(vector<int>& sm, int i, int j) {
        // [i, j]偶数个房子，邮箱放在中间[ml, mr]任意的地方
        // 奇数个房子，邮箱放在中间的房子(ml = mr)
        // 默认放在ml
        int ml = (i + j) >> 1, mr = (i + j + 1) >> 1;
        // sm[j + 1]: 0, 1, ..., ml, ml + 1, ..., j
        // sm[mr]: 0, 1, ..., i,..., mr - 1
        // sm[j + 1] - sm[mr]: mr, ...,j的房子的houses[i]的和
        // sm[i]: 0, ..., i - 1
        // sm[ml + 1] - sm[i]: i, ..., ml的房子的houses[i]的和
        // 上面两个想减是房子间的距离, houses[j]-houses[i]
        // ml = mr时都中间的房子减掉了
        // mr = ml + 1时，houses[mr]-houses[ml]也计算到了
        return (sm[j + 1] - sm[mr]) - (sm[ml + 1] - sm[i]);
    }
};

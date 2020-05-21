class Solution {
public:
    int splitArray(vector<int>& nums) {
        static int vm = 1e6;  // 限制条件给定的
        static vector<int> maxdiv(vm + 1, 0);  // [0, 1e6]的最大质因数
        // 2-max 之间的素数
        static unordered_set<int> prime;
        // 欧拉筛法
        if(maxdiv[vm] == 0) {
            //只计算一次
            for(int i = 2; i <= vm; i++) {
                // 2×3×5×7×11×13×15×17=7657650>10^6
                // 同一个j，更新不会超过7次，所以复杂度O(7n)~O(n)
                if(!maxdiv[i]) {
                    // 是质数
                    maxdiv[i] = i;  //素数的最大质因数是自己
                    prime.insert(i);
                    for(int j = 2 * i; j <= vm; j += i) maxdiv[j] = i;
                }
            }
        }
        // cout << prime.size() << endl; 78498

        // 最大公因子gcd(greatest common divisor)可以利用欧几里得算法得到（不断求余）
        /* 动态规划：一种思路以index为比较单位，
        dp[i] = dp[i-1]+1;  nums[i]一个数为一组
        for(j = i - 1; j >= 0; j--)
            if(gcd(nums[i], nums[j]) > 1)
                //[j, i]可以划到一起，剩余[0, j - 1]
                dp[i] = min(dp[i], dp[j - 1] + 1);
            else 
                //如果[0, j - 1]，[j, i]划开，那[j, i]需要额外划分 
                dp[i] = min(dp[i], dp[j - 1] + f[j][i]); 这里f[j][i]不太好解 还不如直接两两判断有没有gcd>1
                // dp[i] <= dp[j - 1] + i - j + 1;
        O(n^2 lgM) 计算gcd是lg量级
        */
        /* 优化的动态规划: dp[x]表示到目前为止[0, i]，以素数x为右端的最小划分
        // [0:2, 1:3, 2:5, ..., n:10] dp[2]=1,dp[3]=f[0]+1=2(前面的数没有大于1的公因子，3只能单独分为一组)
        // 到10这个数f[n]=min(dp[5]:3, dp[2]:1)
        O(nlgM)
        */
        int n = nums.size();
        if(n == 1) return 1;
        // 初始化
        // int vmax = 0;  // 数组中的最大数，存不大于vmax的素数的情况
        // for(int i: nums) vmax = max(vmax, i);
        // vector<int> dp(vmax + 1, INT_MAX);  //dp[x]以素数x为右端的最小划分数
        vector<int> dp(vm + 1, INT_MAX);  //dp[x]以素数x为右端的最小划分数
        vector<int> f(n); //f[i]: 划分[0, i]的最小组数
        dp[maxdiv[nums[0]]] = 1;
        while(nums[0] > 1 && prime.find(nums[0]) == prime.end()) {
            //nums[0]不是素数，可能还有其他质因子
            int prex = maxdiv[nums[0]];            
            while(nums[0] > 1 && nums[0] % prex == 0) nums[0] /= prex; //18=3*3*2
            if(nums[0] > 1) dp[maxdiv[nums[0]]] = 1;
        }
        f[0] = 1;
        vector<int> pri; // 质因子
        for(int i = 1; i < n; i++) {
            // 可以遍历素数，或者求解质因子
            pri.clear();
            pri.push_back(maxdiv[nums[i]]);
            while(nums[i] > 1 && prime.find(nums[i]) == prime.end()) {
                while(nums[i] > 1 && nums[i] % pri.back() == 0) nums[i] /= pri.back();
                if(nums[i] > 1) pri.push_back(maxdiv[nums[i]]);
            }
            f[i] = f[i - 1] + 1; //没有这句报错；因为nums[i]可以单独划分，dp[p]不一定小于f[i-1]+1
            // [2, 3, 5, 7, 2, 7], i:5 dp[7]=4, f[4]=dp[2]=1, f[5]=f[4]+1=2 not 4
            for(int p: pri) {
                // if(dp[p] == INT_MAX) {
                //     // 之前没有出现这个质因数，这个数注定一个为一组
                //     // 以p为右端点的最小划分
                //     dp[p] = f[i - 1] + 1;
                //     //之前出现相同质因数，值不变 [2,3,5,...,5]
                // }
                f[i] = min(f[i], dp[p]);
            }
            for(int p: pri) {
                // 需要更新dp[p]
                // [2,3,5,4,2,5]  dp[5]=3->dp[5]=2
                dp[p] = min(dp[p], f[i]);  // 更新有问题
                // [2,3,5,4,2,10,5] 碰到nums[i]=10就更新dp[5]=2 not 1,不然后一个5更新有误dp[5] 
            }
            /* 实际要从第一次写的动规思路理解: 其实优化的是第二层循环
                f[i] = f[i-1]+1;  //f[i] <= f[i-1]+1
                for(j = i - 1; j >= 0; j--) {
                    if(gcd(nums[i], nums[j]) > 1) {
                        // 通过dp[p]（质因子）可以直接找到以gcd=p>1为左右端点的最小的f
                        // 如果质因子是第一个数，直接dp[p]=1,f[i]=1找到最小划分
                    }
                    else {
                        // 对于两个gcd(nums[i],nums[j])==1的数 [i,j]一个大组还要细分，最大细分为i-j+1组
                        // f[i] = min(f[i], f[j - 1] + [i,j]的最小划分);
                        // 如果j= i-1, f[j - 1] + 2 (因为gcd==1) = f[i-2]+2 >= f[i-1]+1 >= f[i] 没必要再算
                        // 如果是最大细分都没必要计算
                        // 如果[j,i]中间出现了可以连起来的子数组[i-l,i-m]，也可以不再考虑
                        // 因为f[i-1]已经考虑了所有连起来的情况的最小值
                    }
                }
            */
        }
        
        return f[n - 1];
    }
};

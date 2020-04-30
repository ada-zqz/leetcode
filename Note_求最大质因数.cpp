/*
maxdiv[i] = j  数字i的最大质因数为j
*/
// 从小到大，
int n = 1e6;
vector<int> maxdiv(n + 1, 0);  // [1, n]的最大质因数
vector<int> prime{1};          // [1, n]内的质数
maxdiv[1] = 1;
for(int i = 2; i <= n; ++i) {
    if(maxdiv[i] == 0) {       //不是小于i的值的倍数，即为质数
        prime.push_back(i);
        for(int j = i; j <= 1e6; j += i)
            // 2×3×5×7×11×13×15×17=7657650>10^6
            // 同一个j，更新不会超过7次，所以复杂度O(7n)~O(n)
            maxdiv[j] = i;
    }
}

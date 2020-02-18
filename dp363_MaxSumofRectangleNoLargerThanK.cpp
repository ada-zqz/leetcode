class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int sum = 1<<31;
        
        for(int L = 0; L < n; L++) {
            vector<int> w(m, 0);
            for(int R = L; R < n; R++) {
                for(int i = 0; i < m; i++) w[i] += matrix[i][R];
                
                set<int> sumfrominit;  //从w[0]开始的累加数，顺序排列
                sumfrominit.insert(0); //用于判断相等情况
                int acc = 0, wmax = 1<<31;
                for(int v: w) {
                    acc += v;
                    set<int>::iterator it = sumfrominit.lower_bound(acc - k);
                    // 已经保存有[0]，如果累加数小于或者等于k，可以判断最大值
                    // 已经保存i之前的累加acc_i，如果acc_i+val[i]后还小于或等于k，类似上一行注释；
                    // 如果acc_i+val[i]大于k，找到最大的j之前的累加acc_j恰好不小于(>=)acc_i+val[i]-k
                    if(it != sumfrominit.end()) wmax = max(wmax, acc - *it);
//                     if(wmax == k) return k;
                    sumfrominit.insert(acc);
                }
                sum = max(sum, wmax);
            }
        }
        return sum;
    }
};

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int sum = 1<<31;
        
        for(int L = 0; L < n; L++) {
            vector<int> w(m, 0);
            for(int R = L; R < n; R++) {
                for(int i = 0; i < m; i++) w[i] += matrix[i][R];
                
                set<int> sumfrominit; //从w[0]开始的累加数，顺序排列
                sumfrominit.insert(0);
                int acc = 0, wmax = 1<<31;
                for(int v: w) {
                    acc += v;
                    set<int>::iterator it = sumfrominit.lower_bound(acc - k);
                    if(it != sumfrominit.end()) wmax = max(wmax, acc - *it);
                    sumfrominit.insert(acc);
                }
                sum = max(sum, wmax);
            }
        }
        return sum;
    }
};

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int sum = 1<<31, temp;
        
        for(int L = 0; L < n; L++) {
            vector<int> w(m, 0);
            for(int R = L; R < n; R++) {
                for(int i = 0; i < m; i++) w[i] += matrix[i][R];
                for(int up = 0; up < m; up++) {
                    vector<int> wsub (w.begin() + up, w.end());
                    temp = findrowmax(wsub, k);
                    // cout << L << R << " up" << up << " t" << temp << " s" << sum << endl;   
                    if(temp == k) return k;
                    if(temp > k) continue;
                    if(temp >= sum) {
                        sum = temp;
                        break;
                    }
                                         
                }
            }
        }
        return sum;
    }
    int findrowmax(vector<int> w, int k) {
        int sum = w[0], pre = 0, cur;
        int erg = 0;  //遍历，因为k不一定是最大值
        for(int i = 0; i < w.size(); i++) {
            cur = max(w[i], w[i] + pre);
            erg += w[i];
            if(cur == k || erg == k) return k;
            if(cur > k) return sum;
            if(cur > sum) sum = cur;
            swap(pre, cur);
        }
        return sum;
    }
};

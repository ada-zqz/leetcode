class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        multimap<int, vector<int>> mp;
        int m = mat.size();
        int n = mat[0].size();
        int sm = 0;
        for(int i = 0; i < m; i++) sm += mat[i][0];
        mp.insert({sm, vector<int>{m, 0}});
        vector<int> st;
        while(st.size() < k) {
            // 每一行不递减；其他行不变，只变某一行，考虑后一个数的sm一定比考虑前一个数的sm大
            auto p = *mp.begin();
            mp.erase(mp.begin());
            st.push_back(p.first);
            if(p.second[0] == m && n > 1) {
                // 第二小的数字包含一个第二列的数字
                for(int i = 0; i < m; i++) mp.insert({p.first - mat[i][0] + mat[i][1], vector<int>{i, 1}});
            }
            else {
                if(p.second[1] < n - 1) {
                    // 不是最后一列
                    // 有问题
                    // 其他行(第i列)不变，只变某一行，考虑后一个数(第j列)的sm一定比考虑前一个数(第i列)的sm大
                    // 但是若j>i+1，情况要补充的更多，例如所有行变为i+1列的sum也要补充进队列
                    // mat = [[1,3,11],[2,4,6]], k = 5  输出9而不是7
                    mp.insert({p.first - mat[p.second[0]][p.second[1]] + mat[p.second[0]][p.second[1] + 1], vector<int>(p.second[0], p.second[1] + 1)});
                }
            }
        }
        for(int i = 0; i <k ; i++) cout << st[i] << " ";
        return st[k - 1];
    }
};

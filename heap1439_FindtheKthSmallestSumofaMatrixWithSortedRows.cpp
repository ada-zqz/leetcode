class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        set<pair<int, vector<int>>> mp;
        int m = mat.size();
        int n = mat[0].size();
        int sm = 0;
        for(int i = 0; i < m; i++) sm += mat[i][0];
        // 每一行不递减
        // 其他行(第i列)不变，只变某一行，考虑后一个数(第j列)的sm一定比考虑前一个数(第i列)的sm大
        // 但是若j>i+1，情况要补充的更多，例如所有行变为i+1列的sum也要补充进队列
        // 所以每输出一个值到队列，应该更新每一行的数据，即记录sum的同时，记录每一行的列取值，然后更新时每一行列数单独+1
        mp.insert({sm, vector<int>(m, 0)}); //m行，都是第0列
        vector<int> res;
        while(res.size() < k) {
            auto p = *mp.begin();  //mp.begin()是迭代器，mp.begin()->first
            mp.erase(mp.begin());
            res.push_back(p.first);
            // 把比p.first大的数的n个可能补充进队列
            for(int i = 0; i < m; i++) {
                if(p.second[i] < n - 1) {
                    vector<int> cp = p.second;
                    cp[i]++;
                    mp.insert({p.first - mat[i][cp[i] - 1] + mat[i][cp[i]], cp});
                }
            }
        }
        for(int i = 0; i < k; i++)
            cout << res[i] << " ";
        return res[k - 1];
    }
};

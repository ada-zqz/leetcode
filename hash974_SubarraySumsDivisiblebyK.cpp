class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        // 之前固定i，考虑j增加对应的res
        // 另一个思路，固定j，考虑之前计算的i的结果
        int res = 0;
        int n = A.size();
        vector<int> count(K, 0);
        count[0] = 1; // id表示mod出现的次数
        int pre = 0;
        for(int a: A) {
            pre = ((pre + a) % K + K) % K;  // 保证非负
            res += count[pre]++;  // 比如现在sum[0, j]mod后为2，count[2] = c说明有sum[0, i] mod = 2存在c种
        }
        return res;
    }
};

class Solution {
public:
    int expectNumber(vector<int>& scores) {
            unordered_set<int> v;
            // 重复score的简历，一起被看到的简历数期望为1
            // 重复2、3次的例子可以验证
            // 所有可能的情况: (n!)^2，然后找重复2次，3次...对应的可能情况数，过于复杂了
            // 另一种思考：有m个重复score的简历，甲已经看完(A1, A2, A3, A4, ...)
            // 对于乙：第i次拿出Aj的概率为1/m，第一次拿到A1的概率为1/m，第一次拿对应的期望为(2*1/m + 0)/2=1/m
            // 第二次拿对应的期望也是(2*1/m + 0)=1/m
            // 拿了m次，总的期望为m*1/m=1
            for(auto s: scores) v.insert(s);
            return v.size();
    }
};

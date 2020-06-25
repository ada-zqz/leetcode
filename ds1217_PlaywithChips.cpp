class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        // 题目之前理解有点问题
        // chips: 就是公爵。[2,2,3] 
        // pos1,   pos2,   pos3
        //     , cp1/cp2,   cp3 
        int even = 0, odd = 0; //偶数和奇数位置处的chip数
        for(int pos: chips) {
            if(pos & 1) odd++;
            else even++;
        }
        // 移动小的一堆
        return min(even, odd);
    }
};

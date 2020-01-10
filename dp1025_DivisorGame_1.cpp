class Solution {
public:
    bool divisorGame(int N) {
        // 可以借助1,2,3,4,5...理解
        // 偶数A能赢，减1变成奇数给B就行；奇数的话，减一次（一定时奇数）变成偶数，A只能输
        if(N % 2 == 0) {return true;}
        else {return false;}
    }
};

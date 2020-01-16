//一个数分成两份，根据二次函数可以知道平分对应的product最大
//一个数分成三份，固定已分好的一个数，其他两个数相等对应的product才最大，将两个数调整为相等，固定其中一个数看，最初设定的那个数必须相等才能保证最大，所以最后是三个数都相等对应product最大
//依次推论，一个数n分成x份，每个数等于n/x得到的product最大，数n给定，x未知
// derivative of (n/x)^(x) = (n/x)^x (-1 + log(n/x)) n/x=e是导数正负变化的拐点
// https://www.wolframalpha.com/input/?i=derivative+of+%28n%2Fx%29%5E%28x%29
// 即每个数分为2 or 3

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2 or n == 3) {return 1 + (n % 2);}
        int m = n / 3, l = n % 3, r;
        if(l == 0) {r = pow(3, m);}  
        if(l == 1) {r = pow(3, (m - 1)) * 4;}  //l=1: 2,2 (2*2=4, m+1) or 4 (m)
        if(l == 2) {r = pow(3, m) * 2;} 
        return r;
    }
};

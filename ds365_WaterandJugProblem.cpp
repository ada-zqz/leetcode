class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        // ax + by都可以实现（a, b是整数，为正表示装水，为负表示倒水）
        // Bézout's identity — Let a and b be integers with greatest common divisor d. Then, there exist integers x and y such that ax + by = d. More generally, the integers of the form ax + by are exactly the multiples of d. 即ax+by一定是最大公约数d的倍数
        /* 换一种理解，记最大公约数d=gcd(x, y)，x=e*d, y=f*d，e与f的最大公约数为1，否则d不是x,y的最大公约数
           可能实现的z是ax=aed, by=bfd, c(x-y)=(ce-cf)d的组合，所以实现的z都是d的倍数；
           再证d乘以任意大于0的倍数都能实现，即如果z=d能实现，d的任意倍数都能实现。
        现在想x, y是d的倍数，如果都是奇数倍，(x-y)一定是偶数倍，奇数倍和偶数倍组合一定能找到1倍的情况；
        由于e和f的最大公约数为1，所以x,y都是偶数倍的情况不可能；如果一个奇数倍，一个偶数倍，相减为奇数倍，还是能找到1倍的情况。
        所以d的所有倍数都能被实现。
        */
        // 以上分析对应有第三个容器装水，z>x+y都可以
        // 如果只有x，y两个容器装水，z<=x+y，d的不大于z的公倍数都能通过倒来倒去水实现
        if(z == 0) return true;
        if(x + y < z) return false;
        return z % gcd(x, y) == 0;
    }
    int gcd(int& x, int& y) {
        // if(x * y == 0) return x + y;  // 其中一个为0，返回不为0的数，while已经包含了这一个情况
        if(x > y) swap(x, y);  //x<=y
        while(x > 0) {
            y = y % x;
            swap(x, y);
        }
        return y;
    }
};

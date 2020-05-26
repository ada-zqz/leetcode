class Solution {
public:
    bool isPowerOfThree(int n) {
        static int vmax = -1;
        if(vmax < 0) {
            vmax = pow(3, (int)(log(0x7fffffff) / log(3)));
        }
        return n > 0 && vmax % n == 0; 
    }
};

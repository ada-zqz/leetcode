class Solution {
public:
    int numberOfSteps (int num) {
        int res = 0;
        while(num) {
            if(num & 1) num--;
            else num = num >> 1;
            res++;
        }
        return res;
    }
};

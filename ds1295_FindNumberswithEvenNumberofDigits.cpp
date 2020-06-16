class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(auto & i: nums) if(iseven(i)) res++;
        return res;
    }
    bool iseven(int & num) {
        int d = 0;
        while(num > 0) {
            d++;
            num /= 10;
        }
        return d % 2 ? false : true;
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sm(n + 1, 0);
        for(int i = 0; i < n; i++) {
            sm[i + 1] = sm[i] + nums[i];
        }
        int res = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; j++) {
                if(sm[j + 1] - sm[i] >= lower && sm[j + 1] - sm[i] <= upper) res++;
            } 
        }
        return res;
    }
};

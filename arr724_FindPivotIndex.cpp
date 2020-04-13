class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        vector<int> sm(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            sm[i] += sm[i - 1] + nums[i - 1];
        }
        for(int i = 1; i <= n; i++) {
            if(sm[i - 1] == sm[n] - sm[i]) return i - 1;
        }
        return -1;
    }
};

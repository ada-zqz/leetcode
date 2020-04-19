class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int vmin = 0;
        int sm = 0;
        for(int i = 0; i < nums.size(); i++) {
            sm = sm + nums[i];
            vmin = max(vmin, -sm);
        }
        return 1 + vmin;
    }
};

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int vmin = nums[0];
        int sm = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            sm = sm + nums[i];
            vmin = min(vmin, sm);
        }
        if(vmin >= 1) return 1;
        return 1 - vmin;
    }
};

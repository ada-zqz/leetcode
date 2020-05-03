class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        if(k == 0) return true;
        int pre = -1e6;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                if(i - pre <= k) return false;
                else pre = i;
            }
        }
        return true;
    }
};

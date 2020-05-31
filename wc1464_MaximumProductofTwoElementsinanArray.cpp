class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int res = (nums[0] - 1) * (nums[1] - 1);
        int n = nums.size();
        if(nums[n - 2] < 1) res = max(res, (nums[n - 2] - 1) * (nums[n - 1] - 1));
        return res;
    }
};

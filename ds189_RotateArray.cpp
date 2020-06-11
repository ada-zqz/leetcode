class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 || k == 0) return;
        
        k = k % n;
        reverse(nums.begin(), nums.begin() + (n - k));
        reverse(nums.begin() + (n - k), nums.end());
        reverse(nums.begin(), nums.end());
    }
};

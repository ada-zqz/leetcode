class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int count[1000005];
        memset(count, 0, sizeof(count));
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                count[abs(nums[j] - nums[i])]++;
            }
        }
        for(int i = 0; i <= 1e6; i++) {
            if(count[i] >= k) return i;
            k -= count[i];
        }
        return -1;
    }
};

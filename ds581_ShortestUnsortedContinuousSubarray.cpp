class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //先排序，在前后比较
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int len = nums.size();
        int i = 0, j = len - 1;
        while(i < len && nums[i] == sorted[i]) i++;
        while(j > i && nums[j] == sorted[j]) j--;
        return j - i + 1;
    }
};

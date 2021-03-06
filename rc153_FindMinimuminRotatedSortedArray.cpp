class Solution {
public:
    int findMin(vector<int>& nums) {
        return findsub(nums, 0, nums.size() - 1);
    }
    int findsub(vector<int>& nums, int b, int e) {
        //b-e的连续序列，b处要小于最后的值，对应最小值
        if(nums[b] < nums[e] || b == e) return nums[b];  
        int mid = (b + e) / 2;
        if(nums[mid] > nums[e]) return findsub(nums, mid + 1, e);
        else return findsub(nums, b, mid);
    }
};

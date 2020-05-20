class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 将nums按[1,2,3,...]存储，遇到nums[i] != i+1返回i+1
        int n = nums.size();
        // swap讲nums的位置调动
        for(int i = 0; i < n; i++) {
            // 非正的不管
            // i前面都排好了或者有非正数不排
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                // 比如1不在nums[0](=pre)的位置，令nums[0]=1，继续考虑nums[i] = pre的情况直到排好或者不能排
                swap(nums[nums[i] - 1], nums[i]);
        }    
        for(int i = 0; i < n; i++) {
            // [1, 2, 4], [1, 2, -1, 4]
            if(nums[i] != i + 1) return i + 1;
        }
        // nums = [1, 2, 3, 4]
        return n + 1;
    }
};

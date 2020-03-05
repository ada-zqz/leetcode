class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            while(nums[r] % 2 == 0 && l < r) r--;
            if(l < r) {
                //r指向奇数
                while(nums[l] & 1 && l < r) l++;
                if(l < r) {
                    swap(nums[l], nums[r]);
                    l++;
                    r--;
                }
            }
        }
        return nums;
    }
};

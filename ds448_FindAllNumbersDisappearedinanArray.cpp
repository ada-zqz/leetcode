class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int m = abs(nums[i]) - 1; //nums[i]对应数字m+1
            nums[m] = -abs(nums[m]);   //m+1出现了，所以m+1的位置标为负数
        }
        vector<int> now;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) now.push_back(i + 1);
        }
        return now;
    }
};

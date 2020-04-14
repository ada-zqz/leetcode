class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() == 1) return false;
        if(k == 0) {
            for(int i = 0; i < nums.size() - 1; i++) {
                if(nums[i] == 0 && nums[i + 1] == 0) return true; // [0, 0] 0
            }
            return false; // [0] [1, 2]
        }
        k = abs(k);
        int pre = 0;
        vector<vector<int>> count(k, vector<int>(2, -1));
        for(int i = 0; i < nums.size(); i++) {
            // if(i > 0 && nums[i - 1] == 0 && nums[i] == 0) return true;  //[..., 0, 0, ...]
            pre = (pre + nums[i]) % k;
            if(pre == 0) {
                if(count[pre][0] == -1 && nums[i] < k)  {
                    if(nums[i] != 0) return true; // [1, 1] 2
                }
                if(count[pre][0] == 0 && i - count[pre][1] >= 1) return true; // [2, 2] 2
                
            }
            if(count[pre][0] == -1) {
                count[pre][0]++;
                count[pre][1] = i;
            }
            else if(i - count[pre][1] > 1) {
                return true;
            }
        }
        return false;
    }
};

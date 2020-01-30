class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
        if(nums.size() < 2)
            return 1;
        
        int n = nums.size(), pre = nums[0] - nums[1];
        int res = 1;
        for(int i = 1; i < n; i++) {
            int now = nums[i] - nums[i - 1];
            if((now * pre < 0) || (pre == 0 && now != 0)) { 
                res += 1;
                pre = now;
            }
        }
        return res;
    }
};

//例子: [3, 3, 3, 2, 5], [2, 3, 3, 5]

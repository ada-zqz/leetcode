class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0) return;
        
        int n = nums.size();
        int mv = 0;
        while(mv++ < k) {
            int pre = nums[0];
            for(int i = 1; i < n; i++) {
                int tmp = nums[i];
                nums[i] = pre;
                pre = tmp;
            }
            nums[0] = pre;
        }
    }
};

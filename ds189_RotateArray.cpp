class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0) return;
        
        int n = nums.size();
        int start = 0, cur = 0, mv = 0;
        int pre = nums[0];
        while(mv < n) {
            do{
                int tmp = nums[(cur + k) % n]; //nums[i]交换到nums[(i + k) % n]
                nums[(cur + k) % n] = pre;
                pre = tmp;
                mv++;
                cur = (cur + k) % n;
            }while(cur != start); // 嵌套了 [-1,99,3,100] 2
            start++;
            cur = start;
            pre = nums[cur];
        }
    }
};

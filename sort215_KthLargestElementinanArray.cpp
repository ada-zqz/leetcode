class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        for(int i = len/2 - 1; i >= 0; i--) {
            //建最大堆
            siftdown(i, nums);
        }
        int tmp;
        for(int i = 1; i <= k; i++) {
            tmp = nums[0];  //最大元素
            nums[0] = nums[len - i];
            nums.pop_back();
            siftdown(0, nums);
        }
        return tmp;
    }
    void siftdown(int i, vector<int>& nums) {
        int len = nums.size();
        int j = 2 * i + 1;  //父节点i的关键值较小的子节点
        int tmp = nums[i];  //保存父节点
        while(j < len) {
            if(j < len - 1 && (nums[j] < nums[j + 1])) j++;  //取最大值
            if(tmp < nums[j]) {
                nums[i] = nums[j];
                i = j;
                j = 2 * j + 1;
            }
            else break;
        }
        nums[i] = tmp;
    }
};

class Solution {
public:
    vector<int> tmp;
    vector<int> sortArray(vector<int>& nums) {
        //归并排序 mergesort
        tmp = vector<int>(nums.size());
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
    void mergesort(vector<int>& nums, int l, int r) {
        if(l < r) {
            int mid = (l + r) / 2;
            mergesort(nums, l, mid);
            mergesort(nums, mid + 1, r);
            merge(nums, l, mid, r);
        }
    }
    void merge(vector<int>& nums, int l, int mid, int r) {
        int lt = l, rt = mid + 1, id = l;
        while(lt <= mid && rt <= r) {
            if(nums[lt] <= nums[rt]) tmp[id++] = nums[lt++];
            else tmp[id++] = nums[rt++];
        }
        while(lt <= mid) tmp[id++] = nums[lt++];
        while(rt <= r) tmp[id++] = nums[rt++];
        for(int i = l; i <= r; i++) nums[i] = tmp[i];
    }
};

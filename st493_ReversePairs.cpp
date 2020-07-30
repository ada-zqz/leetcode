class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return MergeSort(nums, 0, nums.size());
    }
    int MergeSort(vector<int>& nums, int start, int end){
        if(end - start <= 1) return 0; 
        int mid = (start + end)/2; 
        int cnt = MergeSort(nums, start, mid) + MergeSort(nums, mid, end); 
        // 已经部分排好序
        for(int i = start, j = mid; i < mid; i++){
            while(j < end && nums[i] / 2. > nums[j]) j++; 
            cnt += j - mid; 
        }
        inplace_merge(nums.begin() + start, nums.begin() + mid, nums.begin() + end); 
        return cnt; 
    }
};

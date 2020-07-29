class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        for(int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + nums[i];
        return MergeSort(sums, 0, n + 1, lower, upper);
    }

    int MergeSort(vector<long long>& sums, int start, int end, int lower, int upper) {
        // n = 0, return 0
        if(end - start <= 1) return 0;
        int mid = (start + end) / 2;
        // [start, mid), [mid, end)已经根据sum排好序
        int count = MergeSort(sums, start, mid, lower, upper) 
                  + MergeSort(sums, mid, end, lower, upper);
        for(int i = start; i < mid; i++) {
            auto j = lower_bound(sums.begin() + mid, sums.begin() + end, sums[i] + lower);
            auto k = upper_bound(sums.begin() + mid, sums.begin() + end, sums[i] + upper);
            count += k - j;
        }
        // 排好序
        inplace_merge(sums.begin() + start, sums.begin() + mid, sums.begin() + end);
        return count;
    }
};

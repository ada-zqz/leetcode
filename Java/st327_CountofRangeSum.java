class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        int n = nums.length;
        long[] sums = new long[n + 1];
        for(int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + nums[i];
        return MergeSort(sums, 0, n + 1, lower, upper);
    }
    private int MergeSort(long[] sums, int start, int end, int lower, int upper) {
        // n = 0, return 0
        if(end - start <= 1) return 0;
        int mid = (start + end) / 2;
        // [start, mid), [mid, end)已经根据sum排好序
        int count = MergeSort(sums, start, mid, lower, upper) 
                  + MergeSort(sums, mid, end, lower, upper);
        int j = mid, k = mid, t = mid;
        long[] cache = new long[end - start];
        for(int i = start, r = 0; i < mid; i++, r++) {
            // 只走一遍O(n)
            while(k < end && sums[k] - sums[i] < lower) k++;
            while(j < end && sums[j] - sums[i] <= upper) j++;
            count += j - k;
            while(t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
            cache[r] = sums[i];
        }
        // 源数组，起始位置，目标数组，起始位置，长度
        System.arraycopy(cache, 0, sums, start, t - start);
        return count;
    }
}

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        // binary search
        // 如果比mid小的值count<k,lo = mid+1
        int lo = matrix[0][0];
        int hi = matrix[m - 1][n - 1];
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            int j = n - 1; 
            // matirx[0][n-1] < mid,count += n-1
            // matrix[0][j] > mid, j--
            // 直到matrix[0][j] <= mid 这一行count加上j+1; 
            // matrix[1][j+1]>matrix[0][j]>mid，但是matrix[1][j]可能 <= mid
            int count = 0;
            for(int i = 0; i < m; i++) {
                //j相同，i增大的值变大
                while(j >= 0 && matrix[i][j] > mid) j--;
                count += (j + 1);
            }
            // count == k对应的mid不一定是数组中的值，hi=mid
            // 如果是数组中的值，lo会不断逼近hi，当lo<hi时，mid<hi，count<k，最终lo=hi
            // 如果不是数组中的值，下一次mid会不断趋近
            // lo == hi时一定是数组中的值，因为对应第kth最小值
            // 比lo小的<k，比hi小的>=k，lo+1==hi，那么就是考虑lo+1这个数之后count=k
            if(count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, r = A.size() - 1;
        while(l < r) {
            int mid = (l + r) >> 1;
            if(A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
                l = mid;
                break;
            }
            else if(A[mid] > A[mid - 1] && A[mid] < A[mid + 1]) {
                l = mid + 1;
            }
            else r = mid;
        }
        return l;
    }
};

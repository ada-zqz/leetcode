class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int k = (m + n) / 2;
        int ans1, ans2;
        ans1 = findkth(nums1, nums2, 0, m, 0, n, k + 1);  //从小到大第k+1大的数
        if((m + n) % 2 == 0) {
            ans2 = findkth(nums1, nums2, 0, m, 0, n, k);
            cout << ans1 << " " << ans2 <<endl;
            return (double(ans1) + ans2) / 2;
        }
        return ans1;
    }
    int findkth(vector<int>& nums1, vector<int>& nums2, int l1, int r1, int l2, int r2, int k) {
        int m = r1 - l1, n = r2 - l2;
        if(m > n) return findkth(nums2, nums1, l2, r2, l1, r1, k);
        if(m == 0) {
            //前一项已经数完
            return nums2[l2 + k - 1];
        }
        if(k == 1) return min(nums1[l1], nums2[l2]);
        //要数k个最小的出来
        //比较第一个数组的第k/2个与第二个数组的第k/2个
        //这两个数小的那个不会大于等于第k大的数，如果大于等于的话，因为总数目就(k/2+k/2)，与大于的假设矛盾
        //小的那个可以剔除，变成找k-k/2个最小的；相等的话删掉任何一个都是可以的
        int cmp = min(m, k / 2) - 1;
        if(nums1[l1 + cmp] <= nums2[l2 + k / 2 - 1]) {
            l1 = l1 + cmp + 1;
            return findkth(nums1, nums2, l1, r1, l2, r2, k - (cmp + 1));
        }
        else {
            l2 = l2 + k / 2;
            return findkth(nums1, nums2, l1, r1, l2, r2, k - k / 2);
        }
    }
};

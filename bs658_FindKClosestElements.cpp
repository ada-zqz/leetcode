class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int lo = 0, hi = n - k; //输出数组的起点
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            // 若输出是[mid, mid + k - 1]，即这个范围包括了x，且x=mid or mid+k-1都可能
            // --- mid --- mid + k - 1 --- mid + k ---- x -----
            // --- mid ---------- x -- mid + k - 1 ---- mid + k ---- x更靠近mid+k,mid往右移
            // --- mid -- x ---------- mid + k - 1 ---- mid + k ---- x更靠近mid,mid往左移
            // ----- x --- mid --- mid + k - 1 --- mid + k ---- 
            if((x - arr[mid]) > (arr[mid + k] - x)) lo = mid + 1; // hi>lo,mid+k不会超出范围
            //mid+k更改取近范围，所以mid应该往右移
            else hi = mid;
        }
        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};

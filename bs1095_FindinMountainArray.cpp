/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mA) {
        int l = 0, r = mA.length() - 1;
        if(target < mA.get(l) && target < mA.get(r)) return -1;
        
        int mid, vm, vl, vr;
        while(l < r) {
            mid = (l + r) >> 1;
            vm = mA.get(mid);
            vl = mA.get(mid - 1);
            vr = mA.get(mid + 1);
            if(vl < vm && vm > vr) break;
            else if(vl < vm && vm < vr) l = mid + 1;
            else r = mid;
        }
        if(l == r) {
            mid = l;
            vm = vl;
        }
        if(target > vm) return -1;
        if(target == vm) return mid;
        
        int v;
        l = 0, r = mid - 1;
        while(l < r) {
            int m = (l + r) >> 1;
            v = mA.get(m);
            if(v == target) return m;
            else if(v < target) l = m + 1;
            else r = m;
        }
        // l == r
        if(mA.get(l) == target) return l;
        
        l = mid + 1, r = mA.length() - 1;
        while(l < r) {
            int m = (l + r) >> 1;
            v = mA.get(m);
            if(v == target) return m;
            else if(v > target) l = m + 1;
            else r = m;
        }
        return mA.get(l) == target ? l : -1;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //快排，O(1)的额外空间，但是题目要求不能改变数组
        //二分查找比mid小的个数，重复的数在多的那边
        int len = nums.size();  //n+1
        int l = 1, r = len - 1;
        while(l < r) {
            int mid = (l + r) / 2;    
            int smaller = 0, larger = 0;
            for(auto v: nums) {
                if(v <= mid && v >= l) smaller++;
                else if(v> mid && v <= r) larger++;
            }
            if(smaller > larger) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

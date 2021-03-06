class Solution {
public:
    int longestSubarray(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1) return 0;
        
//         int i = 0;
//         while(i < n && nums[i] == 0) i++;
//         if(i == n) return 0;
        
        
//         int res = 1, pre1 = 1, pre2 = 1;
//         int meet = 0;
//         for(i = ++i; i < n; i++) {
//             if(nums[i]) {
//                 pre2++;
//                 pre1++;
//                 res = max(res, pre2);
//             }
//             else {
//                 //遇到0
//                 if(meet == 0) {
//                     meet = 1;
//                     pre1 = 0;
//                 }
//                 else {
//                     pre2= pre1;
//                     pre1 = 0;
//                 }
//             }
//         }
//         if(nums[0] == 1 && meet == 0) res--;
        
//         return res;
        
        //sliding window
        // j-i不会递减
        int i = 0, j, k = 1;
        for (j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) k--;
            if (k < 0 && nums[i++] == 0) k++; //i++保证j-i不会递减
        }
        return j - i - 1;
    }
};

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> mp; //sm, index
        int sm = 0;
        for(int i = 0; i < n; i++) {
            sm += arr[i];
            // sm单调递增的，不用担心有相同的sm对应不同的i
            mp[sm] = i;
        }
        
        int vmin = 0x3f3f3f, left = 0x3f3f3f;
        sm = 0;
        mp[0] = -1;
        for(int i = 0; i < n - 1; i++) {
            sm += arr[i];
            if(mp.find(sm - target) != mp.end()) {
                // 0-i: sm[i]; i+1-j:target; 0-j:sm[j]
                left = min(left, i - mp[sm - target]);
            }
            if(left < 0x3f3f3f && mp.find(sm + target) != mp.end()) {
                //左边的子序列找到，找右边的子序列
                vmin = min(vmin, left + mp[sm + target] - i);
            }
        }
        return vmin >= 0x3f3f3f ? -1 : vmin;
    }
};

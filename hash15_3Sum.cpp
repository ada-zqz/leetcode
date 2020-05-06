class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 3 || 3 * nums[0] > 0 || 3 * nums[n - 1] < 0) return res;
        
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue; //重复，前一个i考虑的范围更广，肯定已经包括了
            int a = nums[i];
            if(a + 2 * nums[i + 1] > 0) break; //最小的情况已经不满足sum<=0
            for(int j = i + 1; j < n - 1; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue; //重复
                int b = a + nums[j];
                if(b + nums[j + 1] > 0) break;
                for(int k = j + 1; k < n; k++) {
                    if(k > j + 1 && nums[k] == nums[k - 1]) continue;
                    int c = b + nums[k];
                    if(c > 0) break;
                    else if(c == 0) {
                        res.push_back(vector<int>{a, b - a, nums[k]});
                        break;
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 3 || 3 * nums[0] > 0 || 3 * nums[n - 1] < 0) return res;
        
        // O(n^2)
        for(int i = 0; i < n - 2; i++) {
            int t = -nums[i];
            int front = i + 1;
            int back = n - 1;
            while(front < back) {
                int sm = nums[front] + nums[back];
                if(sm > t) back--;
                else if(sm < t) front++;
                else {
                    // a+b+c = 0
                    vector<int> v(3);
                    v[0] = nums[i];
                    v[1] = nums[front];
                    v[2] = nums[back];
                    res.push_back(v);
                    
                    // 去掉复本
                    while(front < n - 1 && nums[front] == v[1]) front++;
                    while(back > i + 1 && nums[back] == v[2]) back--;
                }
            }
            while(i < n - 3 && nums[i + 1] == nums[i]) i++;
        }
        return res;
    }
};

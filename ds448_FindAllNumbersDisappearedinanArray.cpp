class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> exist(nums.size(), false);
        for(auto n: nums) exist[n - 1] = true;
        vector<int> now;
        for(int i = 0; i < nums.size(); i++) {
            if(!exist[i]) now.push_back(i + 1);
        }
        return now;
    }
};

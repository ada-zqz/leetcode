class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        vector<int> res(2);
        for(int i = 0; i < nums.size(); i++) {
            if(s.find(target - nums[i]) != s.end()) {
                res[0] = s[target - nums[i]];
                res[1] = i;
                break;
            }
            else {
                s[nums[i]] = i;
            }
        }
        return res;
    }
};

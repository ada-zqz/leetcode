class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> res;
        for(int i: nums) {
            if(st.find(i) == st.end()) st.insert(i);
            else res.push_back(i);
        }
        for(int i = 1; i <= nums.size(); i++) {
            if(st.find(i) == st.end()) {
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};

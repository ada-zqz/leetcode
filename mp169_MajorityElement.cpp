class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major, count = 0;
        for(auto n : nums) {
            if(count == 0) {
                count++;   //the previous ones do not influence the remainder
                major = n;
            }
            else if(major == n) count++;
            else count--;
        }
        return major;
    }
};

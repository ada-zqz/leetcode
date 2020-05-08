class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;  // 最大的是包含hi的，最小的是包含lo的
        while(lo < hi) {
            int sm = numbers[lo] + numbers[hi];
            if(sm > target) hi--;
            else if (sm < target) lo++;
            else return vector<int>{lo + 1, hi + 1};
        }
        return vector<int> {0, 0};
    }
};

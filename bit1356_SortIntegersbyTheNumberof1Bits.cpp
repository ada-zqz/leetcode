class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
    static bool cmp(int& a, int& b) {
        if(bitset<32>(a).count() == bitset<32>(b).count()) return a < b;
        return bitset<32>(a).count() < bitset<32>(b).count();
    }
};

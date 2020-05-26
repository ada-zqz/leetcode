class Solution {
public:
    bool isPowerOfThree(int n) {
        static unordered_set<int> st;
        if(st.size() == 0) {
            long long pre = 1;
            for(int i = 0; pre <= 0x7fffffff; i++) {
                st.insert(pre);
                pre *= 3;
            }
        }
        return st.find(n) != st.end();
    }
};

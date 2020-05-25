class Solution {
public:
    bool isPowerOfTwo(int n) {
        static unordered_set<int> st;
        if(st.size() == 0) {
            int pre = 1;
            for(int i = 0; i < 31; i++) {
                st.insert(pre);
                pre = pre << 1;
            }
        }
        return st.find(n) != st.end();
    }
};

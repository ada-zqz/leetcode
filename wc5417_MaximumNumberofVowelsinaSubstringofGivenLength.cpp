class Solution {
public:
    int maxVowels(string s, int k) {
        int res = 0;
        deque<int> st;  //元音的下标
        for(int i = 0; i < s.size(); i++) {
            while(!st.empty() && i - st.front() >= k) {
                // 超过k了
                st.pop_front();
            }
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                st.push_back(i);
                if(res < st.size()) res = st.size();
                if(res == k) break;
            }
        }
        return res;
    }
};

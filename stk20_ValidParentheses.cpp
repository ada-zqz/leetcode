class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2) return false;
        stack<char> st;
        for(char b : s){
            if(b == '(' || b == '{' || b == '[') {
                st.push(b);
            }
            else {
                if(st.empty()) return false;
                if(b == ')' && st.top() != '(') return false;
                if(b == '}' && st.top() != '{') return false;
                if(b == ']' && st.top() != '[') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

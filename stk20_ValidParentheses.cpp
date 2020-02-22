class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2) return false;
        stack<char> brk;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') 
                brk.push(s[i]);
            else {
                if(brk.empty()) return false;
                char l = brk.top();
                brk.pop();
                if((s[i] == ')' && l == '(') || (s[i] == ']' && l == '[') || (s[i] == '}' && l == '{')) 
                    continue;
                else 
                    return false;
            }
        }
        if(!brk.empty()) return false;
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        for(int i = 0, j = n - 1; i < n && j >=0; ) {
            while(!isalpha(s[i]) && i < n ) {
                i++;
                if(i == n) break;
            }
            while(!isalpha(s[j]) && j >= 0) {
                j--;
                if(j < 0) break;
            }
            if(i >= j) return true;            
            if(isequal(s[i], s[j])) {
                i++;
                j--;
            }
            else return false;
        }
        return true;  //""
    }
    bool isequal(char & a, char & b) {
        if(isdigit(a) && isdigit(b)) {
            if(a == b) return true;
            else return false;
        }
        else if(!isdigit(a) && !isdigit(b)) {
            if(a == b or abs(a - b) == 32) return true;
            else return false;
        }
        
        return false;
    }
    bool isalpha(char & a) {
        if(isdigit(a)) return true;
        if((a >= 'a' && a <= 'z') or (a >= 'A' && a <= 'Z')) return true;
        return false;
    }                  
};

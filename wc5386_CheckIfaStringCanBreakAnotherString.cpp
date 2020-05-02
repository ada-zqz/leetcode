class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool t = true;
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] < s2[i]) {
                t = false;
                break;
            }
        }
        if(!t) {
            t = true;
            for(int i = 0; i < s1.size(); i++) {
                if(s1[i] > s2[i]) {
                    t = false;
                    break;
                }
            }
        }
        return t;
    }
};

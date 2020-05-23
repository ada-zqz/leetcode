class Solution {
public:
    int dayOfYear(string date) {
        static vector<int> y1 {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        static vector<int> y2 {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        static vector<int> s1 {0};
        static vector<int> s2 {0};
        if(s1.size() == 1) {
            for(int i = 1; i < 12; i++) {
                s1.push_back(s1[i - 1] + y1[i - 1]);
                s2.push_back(s2[i - 1] + y2[i - 1]);
            }
        }
        
        vector<int> s;
        int year = stoi(date.substr(0, 4));
        int mon = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));
        if(year % 4 == 0 && year % 100 != 0) s = s2;
        else s = s1;
        
        int res = 0;
        res = s[mon - 1] + d;
        return res;
    }
};

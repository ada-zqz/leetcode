class Solution {
public:
    double average(vector<int>& s) {
        auto m = minmax_element(s.begin(), s.end()); 
        double res = 0;
        int n = s.size();
        for(auto i: s) {res += i;}
        res -= *m.first;
        res -= *m.second;
        res = res / (n - 2);
        return res;
    }
};

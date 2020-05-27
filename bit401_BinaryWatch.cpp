class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for(int h = 0; h <= 11; h++) {
            for(int m = 0; m <= 59; m++) {
                if(bitset<10>(h << 6 | m).count() == num)  {
                    string s;
                    s = to_string(h) + ":" + (m < 10 ? "0" + to_string(m) : to_string(m));
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};

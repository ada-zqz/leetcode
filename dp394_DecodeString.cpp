class Solution {
public:
    string decodeString(string s) {
        int i =0;
        return decodesub(s, i);
    }
    string decodesub(const string& s, int& i) {
        string res;
        while(i < s.size() && s[i] != ']') {
            if(isdigit(s[i])) {
                int rp = 0;
                while(i < s.size() && isdigit(s[i])) {
                    rp = rp * 10 + s[i++] - '0';  //重复次数
                }
                i++; //上一行数字后对应'[', 再i++
                string sub = decodesub(s, i);
                i++; //过掉']'
                
                while(rp-- > 0) {
                    res += sub;
                }
            }
            else {
                //字符
                res += s[i++];
            }
        }
        return res;
    }
};

class Solution {
public:
    string decodeString(string s) {
        stack<int> ks;
        stack<string> cs;
        int repeat = 0;
        string rs = "", res = "";
        int left = 0, right = 0;  //左右括号
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9' ) {
                if(rs != "") {
                    cs.push(rs);
                    rs = "";
                }
                repeat = repeat * 10 + s[i] - '0';
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                rs.append(&s[i], 1);
            }
            else if(s[i] == '[') {
                left += 1;
                ks.push(repeat);
                repeat = 0;
            }
            else if(s[i] == ']') {
                right += 1;
                if(right < left) {
                    int k = ks.top();
                    ks.pop();
                    string cnew = "";
                    for(int j = 0; j < k; j++) {
                        cnew.append(rs);
                    }
                    rs = "";
                    string c = cs.top();
                    cs.pop();
                    c.append(cnew);
                    cs.push(c);
                }
                else {
                    if(rs != "") {
                        cs.push(rs);
                        rs = "";
                    }
                    int k = ks.top();
                    ks.pop();
                    string c = cs.top();
                    cs.pop();
                    cout<<k<<c<<endl;
                    string cnew = "";
                    for(int j = 0; j < k; j++) {
                        cnew.append(c);
                    }
                    res.append(cnew);
                }
            }
        }
        res.append(rs);  //最后出现字符的情况
        return res;
    }
};

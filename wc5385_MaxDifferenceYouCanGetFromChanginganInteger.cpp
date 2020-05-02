class Solution {
public:
    int maxDiff(int num) {
        if(num <= 9) return 8;
        vector<int> v = denum(num);
        vector<int> w = v;
        int i;
        for(i = 0; i < v.size(); i++) {
            if(v[i] != 9) break;
        }
        int c = v[i];
        for(int j = i; j < v.size(); j++) {
            if(v[j] == c) v[j] = 9;
        }
        int a = tonum(v);
        for(int j = 0; j < w.size(); j++) {
            if(j == 0 && w[j] != 1) {
                c = w[j];
                for(int k = 0; k < w.size(); k++) {
                    if(w[k] == c) w[k] = 1;
                }
                break;
            }
            else {
                // 第一位是1
                if(w[j] == 0 || w[j] == w[0]) continue;  // 第一位不能为0
                else {
                    c = w[j];
                    for(int k = j; k < w.size(); k++) {
                        if(w[k] == c) w[k] = 0;
                    }
                    break;
                }
            }
        }
        int b = tonum(w);    
        // cout << a << " " << b << endl;
        return a - b;
    }
    
    vector<int> denum(int num) {
        vector<int> res;
        while(num / 10) {
            res.push_back(num % 10);
            num /= 10;
        }
        res.push_back(num);
        reverse(res.begin(), res.end());
        // 123 - > 1,2,3
        return res;
    }
    int tonum(vector<int> v) {
        int res = 0;
        for(int i: v) {
            res = res * 10 + i;
        }
        return res;
    }
};

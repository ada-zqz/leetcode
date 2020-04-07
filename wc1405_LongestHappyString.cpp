class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a) pq.push({a, 'a'});
        if(b) pq.push({b, 'b'});
        if(c) pq.push({c, 'c'});
        string ans = "";
        while(pq.size() > 1) {
            auto f = pq.top(); pq.pop();
            auto s = pq.top(); pq.pop();
            if(f.first >= 2) {
                // ans += f.second + f.second; 结果有错
                ans += f.second;
                ans += f.second;
                f.first -= 2;
            }
            else {
                ans += f.second;
                f.first--;
            }
            // a >= b
            // if b >= a - 2, b = b - 2; a >= b 下一回合字母首尾不会重合
            // if b < a - 2 那更不会重合
            if(s.first >= f.first && s.first >= 2) {
                ans += s.second;
                ans += s.second;
                s.first -= 2;
            }
            else {
                ans += s.second;
                s.first--;
            }
            if(f.first > 0) pq.push(f);
            if(s.first > 0) pq.push(s);
        }
        if(!pq.empty()) {
            auto f = pq.top(); 
            if(f.first >= 2) {
                ans += f.second;
                ans += f.second;
            }
            else {
                ans += f.second;
            }
        }
        return ans;
    }
};

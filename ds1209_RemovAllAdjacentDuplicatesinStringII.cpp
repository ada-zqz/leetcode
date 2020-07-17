class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> stack = {{0, '#'}}; //简化下面的判断表达式
        for(char c: s) {
            if(stack.back().second != c) {
                stack.push_back({1, c});
            } 
            else if(++stack.back().first == k)
                stack.pop_back();
        }
        string res;
        for(auto& r: stack) {
            res.append(r.first, r.second);
        }
        return res;
    }
};

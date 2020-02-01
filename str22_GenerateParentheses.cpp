class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(res, "", n, 0);
        return res;
    }
    void dfs(vector<string>& res, string sg, int l, int r) {
        if(l == 0 && r == 0) {
            res.push_back(sg);
            return;
        }
        if(l > 0) {
            dfs(res, sg + '(', l - 1, r + 1);
        }
        if(r > 0) {
            dfs(res, sg + ')', l, r - 1);
        }
    }
};

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m = target.size();
        int j = 0;
        vector<string> s;
        for(int i = 1; i <= n; i++) {
            if(i == target[j]) {
                s.push_back("Push");
                j++;
            }
            else if(i < target[j]) {
                s.push_back("Push");
                s.push_back("Pop");
            }
            if(j == m) break;
        }
        return s;
    }
};

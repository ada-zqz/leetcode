class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int cnt = 0;
        // edges是从根节点到子节点排序好了的
        for(int i = edges.size() - 1; i >= 0; i--) {
            if(hasApple[edges[i][1]]) {
                cnt++;
                hasApple[edges[i][0]] = true;
            }
        }
        return 2 * cnt;
    }
};

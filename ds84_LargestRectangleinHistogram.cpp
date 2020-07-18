class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0) return 0;
        vector<int> left(n, -1), right(n, n);
        for(int i = 1; i < n; i++) {
            int pre = i - 1;
            // O(n^2)
            // while(pre >= 0 && heights[pre] >= heights[i]) pre--;
            while(pre >= 0 && heights[pre] >= heights[i]) pre = left[pre];
            left[i] = pre; //第一个不行的位置
        }
        for(int i = n - 2; i >= 0; i--) {
            int pre = i + 1;
            while(pre < n && heights[pre] >= heights[i]) pre = right[pre];
            right[i] = pre;
        }
        int res = 0;
        for(int i = 0; i < n; i++) res = max(res, heights[i] * (right[i] - left[i] - 1));
        return res;
    }
};

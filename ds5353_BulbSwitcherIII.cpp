class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size();
        int ans = 0, pos = 0;
        for(int i = 0; i < n; i++) {
            int nowpos = light[i];
            pos = max(pos, nowpos); //现在打开的最右的灯泡 标记位于1-n
            if(pos == i + 1) ans++; //已经打开了i+1个灯泡
        }
        return ans;
    }
};

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        int mask = 0; //用来表示a,e,i,o,u是否出现偶数次
        vector<int> maskminpos(1<<5);
        fill(maskminpos.begin(), maskminpos.end(), 1e6);
        maskminpos[0] = -1; //偶数次，i-(-1)即为长度
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') mask ^= 1; //异或，偶数次出现为0，奇数次出现为1
            if(s[i] == 'e') mask ^= 2;
            if(s[i] == 'i') mask ^= 4;
            if(s[i] == 'o') mask ^= 8;
            if(s[i] == 'u') mask ^= 16;
            //mask  = 0对应整个母串满足条件
            //mask != 0对应某个或某几个元音出现奇数次，i-第一次奇数的位置
            //用数组存储mask对应的最小位置
            maskminpos[mask] = min(maskminpos[mask], i);
            res = max(res, i - maskminpos[mask]);
        }
        return res;
    }
};

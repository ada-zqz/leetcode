#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct Env {
    public:
    int w, h;
    bool operator < (Env e1) {
        return w < e1.w || (w == e1.w && h > e1.h);
    }
    Env(int width, int height){
        w = width;
        h = height;
    } 
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty()) {return 0;}
        vector<Env> envs;
        int n = envelopes.size();
        for(int i = 0; i < n; i++) {
            envs.push_back(Env(envelopes[i][0], envelopes[i][1]));
        }
        sort(envs.begin(), envs.end());
        
        vector<int> dp(n, 1);
        int maxenvs = 1;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(envs[i].h > envs[j].h) {
                    dp[i] = MAX(dp[i], dp[j] + 1);
                }
                maxenvs = MAX(maxenvs, dp[i]);
            }
        }
        return maxenvs;
    }
};

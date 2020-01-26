class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        if(K == 0)
            return 1;
        
        return prob(N, K, r, c);
    }
    
    float prob(int& N, int K, int r, int c) {
        if(r < 0 || r >= N || c < 0 || c >= N) {
            return 0;
        }
        if(K == 0) {
            return 1;
        }
        float pb = 0;
        K -= 1;
        pb = 0.125 * (prob(N, K, r - 1, c + 2) + prob(N, K, r - 1, c - 2) + prob(N, K, r - 2, c + 1) + prob(N, K, r - 2, c - 1) + prob(N, K, r + 1, c + 2) + prob(N, K, r + 1, c - 2) + prob(N, K, r + 2, c + 1) + prob(N, K, r + 2, c - 1));
        return pb;
    }
};

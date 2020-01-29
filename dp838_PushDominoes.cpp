class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int R = 1<<30, D = 0;
        for(int i = 0; i < n; i++) {
            if(dominoes[i] == 'L') {
                if(R >= i) {
                    for(int j = D; j < i; j++) {
                        dominoes[j] = 'L';
                        D = i + 1;
                    }
                }
                else { //R < L
                    for(int j = 1; j <= (i - R - 1) / 2; j++) {
                        dominoes[i - j] = 'L';
                        dominoes[R + j] = 'R';
                    }
                    D = i + 1;
                    R = 1<<30;
                }
                continue;
            }
            if(dominoes[i] == 'R') {
                if(R < i) {
                    for(int j = R + 1; j < i; j++) {
                        dominoes[j] = 'R';
                    }
                    D = i + 1;
                }
                R = i;
                continue;
            }
        }
        if(R < n - 1) {
            for(int j = R + 1; j < n; j++) {
                dominoes[j] = 'R';
            }
        }
        return dominoes;
    }
};

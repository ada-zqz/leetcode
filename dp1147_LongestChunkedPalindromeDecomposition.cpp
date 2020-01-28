class Solution {
public:
    int longestDecomposition(string text) {
        if(text.size() == 1)
            return 1;
        int k = 1, n = text.size();
        for(int i = 0; i < n/2;) {
            if(text[i] == text[n - i - 1]) {
                cout << i << " " << text[i] << " " << text[n - i - 1] << endl;
                k += 2;
                i++;
                continue;
            }
            for(int j = 2; j <= n/2 - i; j++) {
                if(text.substr(i, j) == text.substr(n - i - j, j)) {
                    k += 2;
                    cout << i << " " << j << " " << k << " " << text.substr(i, j) << " " << text.substr(n - i - j, j) << endl;
                    i = i + j;
                }
            }
        }
        return k;
    }
};

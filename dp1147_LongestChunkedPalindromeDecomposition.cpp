class Solution {
public:
    int longestDecomposition(string text) {
        int k = 1, n = text.size();
        for(int i = 0; i < n/2; i++) {
            if(text.substr(0, i + 1) == text.substr(n - i - 1, i + 1)) {
                // cout << i << " " << text.substr(0, i + 1) << " " << text.substr(n - i - 1, i + 1) << endl;
                return 2 + longestDecomposition(text.substr(i + 1, n - 2 * i - 2));
            }
        }
        return (n == 0) ? 0 : 1;
    }
};

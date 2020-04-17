class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // 从[i, j]开始成不成功
                if(sub(board, word, i, j)) return true;
            }
        }
        return false;
    }
    bool sub(vector<vector<char>>& board, string word, int i, int j) {
        if(word.size() == 0) return true;
        int m = board.size(), n = board[0].size();
        // 超出边界，访问过了，不等于word[0]
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '*' || word[0] != board[i][j]) return false;
        
        string ws = word.substr(1, word.size() - 1);
        char tmp = board[i][j];
        board[i][j] = '*';
        if(sub(board, ws, i + 1, j)) return true;
        if(sub(board, ws, i - 1, j)) return true;
        if(sub(board, ws, i, j + 1)) return true;
        if(sub(board, ws, i, j - 1)) return true;
        board[i][j] = tmp;
        return false;
    }
};

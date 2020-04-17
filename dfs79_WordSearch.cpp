class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // 从[i, j]开始成不成功
                if(sub(board, visited, word, i, j)) return true;
            }
        }
        return false;
    }
    bool sub(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int i, int j) {
        if(word.size() == 0) return true;
        int m = board.size(), n = board[0].size();
        // 超出边界，访问过了，不等于word[0]
        if(i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || word[0] != board[i][j]) return false;
        
        string ws = word.substr(1, word.size() - 1);
        visited[i][j] = true;
        if(sub(board, visited, ws, i + 1, j)) return true;
        if(sub(board, visited, ws, i - 1, j)) return true;
        if(sub(board, visited, ws, i, j + 1)) return true;
        if(sub(board, visited, ws, i, j - 1)) return true;
        visited[i][j] = false;
        return false;
    }
};

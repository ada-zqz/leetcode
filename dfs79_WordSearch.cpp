class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // 从[i, j]开始成不成功
                if(sub(board, visited, word, i, j)) return true;
            }
        }
        return false;
    }
    bool sub(vector<vector<char>>& board, vector<vector<bool>> visited, string word, int i, int j) {
        if(word.size() == 0) return true;
        int m = board.size(), n = board[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n) return false;
        if(word[0] != board[i][j]) return false;
        
        if(!visited[i][j]) {
            string ws = word.substr(1, word.size() - 1);
            visited[i][j] = true;
            if(sub(board, visited, ws, i + 1, j)) return true;
            if(sub(board, visited, ws, i - 1, j)) return true;
            if(sub(board, visited, ws, i, j + 1)) return true;
            if(sub(board, visited, ws, i, j - 1)) return true;
            visited[i][j] = false;
        }
        return false;
    }
};

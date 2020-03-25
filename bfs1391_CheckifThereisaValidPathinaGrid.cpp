struct Street {
    int x;
    int y;
    char from;
    Street(int xi, int yi, char fromi): x(xi), y(yi), from(fromi) {}
};

vector<char> dir = {'u', 'd', 'l', 'r'};

class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        bool visited[n][m][26];
        memset(visited, 0, sizeof(visited));
        queue<Street> q;
        for(char d: dir) {
            Street s(0, 0, d);
            q.push(s);
            visited[0][0][d - 'a'] = true;
        }
        
        while(!q.empty()) {
            Street p = q.front();
            q.pop();
            int x = p.x;
            int y = p.y;
            char from = p.from;
            
            // next -> up
            int x2 = x - 1;
            int y2 = y;
            if((grid[x][y] == 2 && from == 'd') || (grid[x][y] == 5 && from == 'l') || (grid[x][y] == 6 && from == 'r')) {
                if(x2 >= 0 && (grid[x2][y2] == 2 || grid[x2][y2] == 3 || grid[x2][y2] == 4) && !visited[x2][y2]['d' - 'a']) {
                    q.emplace(x2, y2, 'd');
                    visited[x2][y2]['d' - 'a'] = true;
                }
            }
            
            // next -> down
            x2 = x + 1;
            y2 = y;
            if((grid[x][y] == 2 && from == 'u') || (grid[x][y] == 3 && from == 'l') || (grid[x][y] == 4 && from == 'r')) {
                if(x2 < n && (grid[x2][y2] == 2 || grid[x2][y2] == 5 || grid[x2][y2] == 6) && !visited[x2][y2]['u' - 'a']) {
                    q.emplace(x2, y2, 'u');
                    visited[x2][y2]['u' - 'a'] = true;
                }
            }
            
            // next -> right
            x2 = x;
            y2 = y + 1;
            if((grid[x][y] == 1 && from == 'l') || (grid[x][y] == 4 && from == 'd') || (grid[x][y] == 6 && from == 'u')) {
                if(y2 < m && (grid[x2][y2] == 1 || grid[x2][y2] == 3 || grid[x2][y2] == 5) && !visited[x2][y2]['l' - 'a']) {
                    q.emplace(x2, y2, 'l');
                    visited[x2][y2]['l' - 'a'] = true;
                }
            }
            
            // next -> left
            x2 = x;
            y2 = y - 1;
            if((grid[x][y] == 1 && from == 'r') || (grid[x][y] == 3 && from == 'd') || (grid[x][y] == 5 && from == 'u')) {
                if(y2 >= 0 && (grid[x2][y2] == 1 || grid[x2][y2] == 4 || grid[x2][y2] == 6) && !visited[x2][y2]['r' - 'a']) {
                    q.emplace(x2, y2, 'r');
                    visited[x2][y2]['r' - 'a'] = true;
                }
            }
        }
        for(char d: dir) {
            if(visited[n - 1][m - 1][d - 'a']) return true;
        }
        return false;
    }
};

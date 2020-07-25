class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        dfs(rooms, visited, 0);
        return visited.size() == rooms.size();
    }
    void dfs(vector<vector<int>>& rooms, unordered_set<int> & visited, int cur) {
        visited.insert(cur);
        for(int k : rooms[cur]) {
            if(visited.find(k) == visited.end()) 
                dfs(rooms, visited, k);
        }
    }
};

    
    

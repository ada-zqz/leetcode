class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // BFS
        unordered_set<int> visited;
        queue<int> to_visit;
        to_visit.push(0);
        while(!to_visit.empty()) {
            int cur = to_visit.front();
            visited.insert(cur);
            to_visit.pop();
            for(int k : rooms[cur]) 
                if (visited.find(k) == visited.end()) to_visit.push(k);
        }
        return visited.size() == rooms.size();
    }
};

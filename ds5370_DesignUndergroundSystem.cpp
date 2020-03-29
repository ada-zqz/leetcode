#include <unordered_map>
using namespace std;

class UndergroundSystem {
public:
    unordered_map<string, pair<int, int>> mp;
    unordered_map<int, pair<string, int>> ps;
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        ps[id] = pair<string, int>(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = ps[id].first;
        int stay = t - ps[id].second;
        string mpkey = startStation + "+" + stationName;
        if(mp.find(mpkey) == mp.end()) {
            mp[mpkey] = pair<int, int>(stay, 1);
        }
        else {
            int sum = mp[mpkey].first;
            int np = mp[mpkey].second;
            mp[mpkey] = pair<int, int>(sum + stay, np + 1);
        }
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string mpkey = startStation + "+" + endStation;
        if(mp.find(mpkey) == mp.end()) return 0.0;
        else {
            return double(mp[mpkey].first)/mp[mpkey].second;
        }
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

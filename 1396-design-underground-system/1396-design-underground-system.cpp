class UndergroundSystem {
    unordered_map<int, pair<int, string>> enter;
    unordered_map<string, unordered_map<string, int>> total, count;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string f, int t) {
        enter[id] = {t, f};
    }
    
    void checkOut(int id, string d, int t) {
        pair<int, string> p = enter[id];
        total[p.second][d]+= t-p.first;
        count[p.second][d]+= 1;
        enter.erase(id);
    }
    
    double getAverageTime(string f, string d) {
        double n = total[f][d];
        int m = count[f][d];
        return n/m; 
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
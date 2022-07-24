class UndergroundSystem {
    unordered_map<int, int> enter;
    unordered_map<int, string> first; 
    unordered_map<string, unordered_map<string, int>> total, count;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        enter[id] = t;
        first[id] = stationName;
    }
    
    void checkOut(int id, string d, int t) {
        int in = enter[id];
        string f  = first[id];
        total[f][d]+= t-in;
        count[f][d]+= 1;
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
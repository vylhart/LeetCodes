class HitCounter {
    vector<int> time;
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        time.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        int i = lower_bound(time.begin(), time.end(), timestamp-300+1) - time.begin();
        return time.size() - i;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
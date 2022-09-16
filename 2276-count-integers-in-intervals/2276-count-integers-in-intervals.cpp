class CountIntervals {
    map<int,int> interval;
    int sum;
public:
    CountIntervals() {
        sum=0;
    }
    
    void add(int left, int right) {
        auto it = interval.lower_bound(left);
        while(it!=interval.end() && it->second <= right){
                left = min(it->second, left);
                right= max(it->first, right);
                sum -= it->first - it->second+1;
                interval.erase(it++);
        }
        
        interval[right] = left;
        sum += right-left+1;
    }
    
    int count() {
        return sum;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */ 
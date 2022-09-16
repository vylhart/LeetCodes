class CountIntervals {
    map<int,int> interval;
    int sum;
public:
    CountIntervals() {
        sum=0;
        //interval[INT_MIN] = INT_MIN;
    }
    
    bool isOverlap(int l1, int r1, int l2, int r2){
        return (l1<=l2 && l2<=r1) || (l1<=r2 && r2<=r1) || (l2<=l1 && l1<=r2);
    }
    
    void add(int left, int right) {
        auto it = interval.lower_bound(left);
        while(it!=interval.end()){
            if(isOverlap(left, right, it->second, it->first)){
                left = min(it->second, left);
                right= max(it->first, right);
                sum -= it->first - it->second+1;
                int tmp = it->first;
                it++;
                interval.erase(tmp);
            }
            else 
                break;
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
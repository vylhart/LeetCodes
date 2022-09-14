class MyCalendar {
    set<pair<int,int>> s;
public:
    MyCalendar() {
        s.insert({INT_MAX, INT_MAX});
        s.insert({INT_MIN, INT_MIN});
    }
    
    
    bool book(int start, int end) {
        auto r = s.lower_bound({start, start});
        auto l = r;
        l--;
        if(l->second <= start && end <= r->first){
            s.insert({start, end});
            return 1;
        }
        return 0;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
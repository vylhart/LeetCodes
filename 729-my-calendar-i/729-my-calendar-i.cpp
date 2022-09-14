class MyCalendar {
    set<int> s,e;
public:
    MyCalendar() {
        
    }
    
    int allendedhere(int time){
        auto startedafterend = lower_bound(s.begin(), s.end(), time);
        int cs = distance(startedafterend, s.end());
        auto endedafterend = lower_bound(e.begin(), e.end(), time);
        int ce = distance(endedafterend, e.end());
        if(ce!=cs)  return -1;
        return ce;
    
    }
    
    bool book(int start, int end) {
        int a = allendedhere(end);
        if(a==-1)   return 0;
        int b = allendedhere(start);
        if(a==b){
            s.insert(start);
            e.insert(end-1);
        }
        return a==b;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
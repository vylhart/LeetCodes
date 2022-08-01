class MedianFinder {
    priority_queue<int> p,q;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(p.empty() || num<p.top()){
            p.push(num);
        }
        else{
            q.push(-num);
        }
        if(p.size()>q.size()+1){
            q.push(-p.top());
            p.pop();
        }
        else if(q.size()>p.size()){
            p.push(-q.top());
            q.pop();
        }
    }
    
    double findMedian() {
        if(p.size()>q.size()){
            return p.top();
        }
        return (p.top()-q.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
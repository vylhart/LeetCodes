class MovingAverage {
    queue<int> q;
    int size;
    double sum;
public:
    MovingAverage(int s) {
        sum = 0;
        size = s;
    }
    
    double next(int val) {
        sum += val;
        q.push(val);
        if(q.size()>size){
            sum -= q.front();
            q.pop();

        }
        return sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
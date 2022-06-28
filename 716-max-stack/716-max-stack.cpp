class MaxStack {
    list<int> l;
    map<int, stack<list<int>::iterator>> h;
public:
    MaxStack() {
    }
    
    void push(int x) {
        l.push_front(x);
        h[-x].push(l.begin());
    }
    
    int pop() {
        int x = l.front();
        l.pop_front();
        h[-x].pop();
        if(h[-x].empty()) h.erase(-x);
        return x;
    }
    
    int top() {
        return l.front();
    }
    
    int peekMax() {
        return -h.begin()->first;
    }
    
    int popMax() {
        int x = h.begin()->first;
        auto it = h[x].top();
        l.erase(it);
        h[x].pop();
        if(h[x].empty()) h.erase(x);
        return -x;
    }
};
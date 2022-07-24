class BrowserHistory {
    stack<string> backStack, forwardStack;
    string current;
public:
    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        forwardStack = stack<string>();
        backStack.push(current);
        current = url;
    }
    
    string back(int steps) {
        while(!backStack.empty() && steps--){
            forwardStack.push(current);
            current = backStack.top();
            backStack.pop();
        }
        return current;
    }
    
    string forward(int steps) {
        while(!forwardStack.empty() && steps--){
            backStack.push(current);
            current = forwardStack.top();
            forwardStack.pop();
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
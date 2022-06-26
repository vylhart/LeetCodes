class Logger {
    unordered_map<string, long> map;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(map.find(message)==map.end() || map[message]+10<=timestamp){
            map[message] = timestamp;
            return 1;
        }
        return 0;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
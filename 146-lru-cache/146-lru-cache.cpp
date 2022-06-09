class LRUCache {
    list<int> dq;
    int cap;
    unordered_map<int, pair<int,list<int>::iterator>> map;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(map.find(key)==map.end())    return -1;
        dq.erase(map[key].second);
        dq.push_front(key);
        map[key].second = dq.begin();
        return map[key].first;
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            dq.erase(map[key].second);
        }
        dq.push_front(key);
        map[key] = {value,dq.begin()};

        
        if(dq.size()>cap){
            int other = dq.back();
            dq.pop_back();
            map.erase(other);
        }
    }
};

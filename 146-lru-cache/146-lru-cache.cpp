class LRUCache {
    list<int> dq;
    int cap;
    int size=0;
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
            size--;
        }
        dq.push_front(key);
        map[key] = {value,dq.begin()};
        size++;

        
        if(size>cap){
            int other = dq.back();
            dq.pop_back();
            map.erase(other);
            size--;
        }
    }
};

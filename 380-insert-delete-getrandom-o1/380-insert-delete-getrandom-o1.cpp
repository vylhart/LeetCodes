class RandomizedSet {
    vector<int> num;
    unordered_map<int,int> map;
    
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val)==map.end()){
            int n = num.size();
            num.push_back(val);
            map[val] = n; 
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(map.find(val)==map.end()){
            return false;
        }
        int i = map[val];
        int n = num.size();
        num[i] = num[n-1];
        map[num[n-1]] = i;
        num.pop_back();
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        int r = rand()%num.size();
        return num[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
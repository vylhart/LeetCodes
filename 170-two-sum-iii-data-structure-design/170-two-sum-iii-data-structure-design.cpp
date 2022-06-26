class TwoSum {
    unordered_map<long, int> map;
public:
    TwoSum() {
    }
    
    void add(int number) {
        map[number]++;
    }
    
    bool find(int value) {
        for(auto k:map){
            long i = k.first;
            if(2*i==value){
                if(map[i]>1)    return 1;
            }
            else if(map.find(value-(long)i)!=map.end()){
                return 1;
            }
        }
        return 0;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
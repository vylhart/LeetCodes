class TwoSum {
    unordered_map<long, int> map;
    vector<int> v;
public:
    TwoSum() {
    }
    
    void add(int number) {
        map[number]++;
        v.push_back(number);
    }
    
    bool find(int value) {
        for(int i:v){
            if(2*i==value){
                if(map[i]>1)    return 1;
            }
            else if(map[value-(long)i]>0){
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
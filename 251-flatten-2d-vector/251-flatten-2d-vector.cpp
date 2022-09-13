class Vector2D {
    int i,n;
    vector<int> v;
public:
    Vector2D(vector<vector<int>>& vec) {
        for(auto i: vec){
            for(int j: i){
                v.push_back(j);
            }
        }
        n = v.size();
        i=0;;
    }
    
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        return !(i==n);
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
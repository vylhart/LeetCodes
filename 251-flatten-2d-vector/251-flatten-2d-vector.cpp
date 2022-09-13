class Vector2D {
    int i,j,n;
    vector<vector<int>> v;
public:
    Vector2D(vector<vector<int>>& vec) {
        n = vec.size();
        v = vec;
        i=0;j=0;
    }
    
    int next() {
        while(i<n && j==v[i].size()){
            i++;
            j=0;
        }
        int x = v[i][j];
        j++;
        return x;
    }
    
    bool hasNext() {
        while(i<n && j==v[i].size()){
            i++;
            j=0;
        }
        return !(i==n);
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
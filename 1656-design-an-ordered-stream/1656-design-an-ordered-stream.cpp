class OrderedStream {
    vector<string> v;
    int index;
    int n;
public:
    OrderedStream(int n) {
        v.resize(n+1);
        index=1;
        this->n = n;
        for(int i=0; i<=n; i++)  v[i]="";
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> ans;
        v[idKey] = value;
        while(index<=n && v[index]!=""){
            ans.push_back(v[index]);
            index++;
        }
        return ans;
    }
};
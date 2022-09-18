class Solution {
    vector<vector<bool>> isPal;
    vector<int> ans;
    int n;
public:
    void find(int i, int x){
        if(i>=n){
            ans.push_back(x);
        }
        for(int j=i; j<n; j++){
            if(isPal[i][j]){
                find(j+1, x|(1<<j));
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        n = s.length();
        isPal.resize(n,vector<bool>(n,0));
        for(int j=0; j<n; j++){
            for(int i=j; i>=0; i--){
                if(i==j || i+1==j)  isPal[i][j] = s[i]==s[j];
                else                isPal[i][j] = s[i]==s[j] && isPal[i+1][j-1];
            }
        }
        find(0,0);
        vector<vector<string>> v;
        vector<string> tmp;
        int prev;
        for(int x: ans){
            prev = 0;
            for(int i=0; i<16; i++){
                if(x&(1<<i)){
                    tmp.push_back(s.substr(prev, i-prev+1));
                    prev = i+1;
                }
            }
            v.push_back(tmp);
            tmp.clear();
        }
        return v;
    }
};
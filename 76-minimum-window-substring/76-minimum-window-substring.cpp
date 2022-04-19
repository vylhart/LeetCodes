class Solution {
public:
    
    bool check(vector<int> &v1, vector<int> &v2){
        for(int i=0; i<256; i++){
            if(v1[i]>v2[i])    return 0;
        }
        return 1;
    }
    
    
    string minWindow(string s, string t) {
        vector<int> freq1(256, 0), freq2(256, 0);
        for(char c: t){
            freq1[c]++;
        }
        
        int n = s.length();
        int i=0,j=0;
        int ans = n;
        int start=0, end=0;
        while(i<=n){
            
            while(j<i && check(freq1, freq2)){
                //cout<<i<<" "<<j<<" "<<ans<<endl;
                if( ans >= i-j ){
                    ans = i-j;
                    start = j;
                    end   = i;
                }
                
                freq2[s[j]]--;
                j++;
            }
            freq2[s[i]]++;
            i++;
        }
        
        string st = "";
        for(int i=start; i<end; i++){
            st += s[i];
        }
        return st;
    }
};
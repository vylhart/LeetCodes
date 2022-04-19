#define MAX 156
class Solution {
public:
    
    bool check(vector<int> &v1, vector<int> &v2){
        for(int i=0; i<MAX; i++){
            if(v1[i]>v2[i])    return 0;
        }
        return 1;
    }
    
    
    string minWindow(string s, string t) {
        vector<int> freq1(MAX, 0), freq2(MAX, 0);
        for(char c: t){
            freq1[c]++;
        }
        
        int n = s.length();
        int i=0,j=0,ans = n,start=0, end=0;
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
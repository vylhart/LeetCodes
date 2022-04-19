#define MAX 130
class Solution {
public:
    
    string minWindow(string s, string t) {

        vector<int> freq(MAX, 0);
        for(char c: t){
            freq[c]++;
        }
        
        int n = s.length();
        int m = t.length();
        int i=0,j=0,ans = n,start=0, end=0;
        
        while(i<=n){
            while(j<i && m==0){
                if( ans >= i-j ){
                    ans = i-j;
                    start = j;
                    end   = i;
                }
                if(freq[s[j]]++==0){
                    m++;
                }
                j++;
            }
            if(freq[s[i]]-- > 0){
                m--;
            }
            i++;
        }
        
        string st = "";
        for(int i=start; i<end; i++){
            st += s[i];
        }
        return st;
    }
};
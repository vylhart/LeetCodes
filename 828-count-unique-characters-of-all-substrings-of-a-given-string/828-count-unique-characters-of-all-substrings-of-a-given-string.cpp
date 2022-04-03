class Solution {
public:
   
    int uniqueLetterString(string s) {
        int ans = 0;
        int n = s.length();
        
        for(char c='A'; c<='Z'; c++){
            int prev=-1, prevprev=-1;
            for(int i=0; i<=n; i++){
                if(i==n && prev!=-1){
                    ans+= (n-prev)*(prev-prevprev);
                }
                else if(prev!=-1 && s[i]==c){
                    ans+= (i-prev)*(prev-prevprev);
                    prevprev = prev;
                    prev = i;
                }
                else if(s[i]==c){
                    prevprev = prev;
                    prev = i;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    bool check(string &s, string &p) {
        int n =s.length();
        int m =p.length();
        vector<int> lps(m,0);
        int i=1, j=0, l=0;
        while(i<m){
            if(p[i]==p[l]){
                lps[i++]=++l;
            }
            else{
                if(l==0)    i++;
                else    l=lps[l-1];
            }
        }
        i=0;
        while(i<n){
            if(s[i]==p[j]){
                j++;
                i++;
                if(j==m){
                    return 1;
                }
            }
            else{
                if(j==0) i++;
                else    j=lps[j-1];
            }
        }
        return 0;
    }
    
    
    int repeatedStringMatch(string a, string b) {
        int n = a.length();
        int m = b.length();
        int l=1, h= max(  (int)ceil((3*m)/n), 3);
        int ans=-1;
        while(l<=h){
            int k = (l+h)/2;
            string t="";
            for(int i=0; i<k; i++)  t+= a;
            if(check(t, b)){
                ans = k;
                h=k-1;
            }
            else{
                l=k+1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        s = " "+s;
        int n = s.length();
        int m = w.length();
        int i=0, j=0;
        int c=0;
        while(i<n){
            while(i<n && s[i]!=' ')    i++;
            i++;
            c++;
            while(i<n && j<m && s[i]==w[j]){
                i++;    j++;
            }
            //cout<<j;
            if(j==m)    return c;
            j=0;
        }
        return -1;
    }
};
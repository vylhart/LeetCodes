class Solution {
public:
    int countBinarySubstrings(string s) {
        int n  = s.length();
        int ans=0;
        for(int i=0; i<n-1; i++){
            if(s[i]!=s[i+1]){
                int j=i, k=i+1;
                while(j>=0 && k<n && s[i]==s[j] && s[i+1]==s[k]){
                    ans++;
                    j--;
                    k++;
                }
            }
        }
        return ans;
    }
};
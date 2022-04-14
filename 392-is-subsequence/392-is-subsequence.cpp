class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length(), i=0;
        for(char c: t){
            if(c==s[i]){
                i++;
            }
        }
        return n==i;
    }
};
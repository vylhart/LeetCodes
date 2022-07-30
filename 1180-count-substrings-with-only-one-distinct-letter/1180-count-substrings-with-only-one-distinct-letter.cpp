class Solution {
public:
    int countLetters(string s) {
        int ans = 1;
        int len = 1;
        for(int i=1; i<s.length(); i++){
            if(s[i]==s[i-1]){
                len++;
            }
            else{
                len=1;
            }
            ans += len;
        }
        return ans;
    }
};
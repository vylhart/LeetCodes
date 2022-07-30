class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> p(26, 0);
        for(int i=0; i<keyboard.length(); i++){
            p[ keyboard[i]-'a' ] = i;
        }
        int ans = 0;
        int prev = 0;
        for(char c: word){
            ans += abs(p[c-'a']-prev);
            prev = p[c-'a'];
        }
        return ans;
    }
};
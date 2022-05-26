class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> map;
        for(string i: wordDict) map[i]=1;
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0]=1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(dp[j] && map[s.substr(j, i-j)]){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
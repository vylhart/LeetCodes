class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> isPal(n,vector<bool>(n,0));
        vector<vector<int>>  count(n, vector<int>(n,0));
        for(int j=0; j<n; j++){
            for(int i=j; i>=0; i--){
                if(i==j){
                    isPal[i][j]=1;
                    count[i][j]=1;
                }
                else if(i+1==j){
                    isPal[i][j] = s[i]==s[j];
                    count[i][j] = 2 + isPal[i][j];
                }
                else{
                    isPal[i][j] = s[i]==s[j] && isPal[i+1][j-1];
                    count[i][j] = isPal[i][j] + count[i+1][j] + count[i][j-1] - count[i+1][j-1];
                }
            }
        }
        return count[0][n-1];
    }
};
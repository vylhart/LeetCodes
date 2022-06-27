class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m = trust.size();
        vector<int> trusted(n+1, 0), trusting(n+1, 0);
        for(int i=0; i<m; i++){
            trusting[trust[i][0]]++;
            trusted[trust[i][1]]++;
        }
        int ans=-1;
        for(int i=1; i<=n; i++){
            if(trusted[i]==n-1 && trusting[i]==0){
                if(ans!=-1)  return -1; 
                ans = i;
            }
        }
        return ans;
    }
};
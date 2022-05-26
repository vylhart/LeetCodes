class Solution {
public:
    int jump(vector<int>& jumps) {
        int n=jumps.size();
        if(jumps[0]==0 || n==1) return 0;
        int ans = 1;
        int jump=jumps[0];
        int i=0;
        while(i<=n){
            if(jump==0) return 0;
            int end = i+jump;
            if(end>=n-1)    return ans;
            
            
            for(int j=i;j<=end;j++){
                jump = max(jump-1, jumps[j]);
            }
            i=end;
            ans++;
        }
        
        return ans;
    }
};
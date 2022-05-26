class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        n = ranges.size();
        int M = INT_MAX;
        vector<int> jumps(n,0);
        for(int i=0; i<n; i++){
            int start = max(0, i-ranges[i]);
            int end = min(n-1, i+ranges[i]);
            jumps[start] = max(end-start, jumps[start]);
        }
        if(jumps[0]==0) return -1;
        int ans = 1;
        int jump=jumps[0];
        int i=0;
        while(i<=n){
            if(jump==0) return -1;
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



class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        pair<int, pair<int,int>> p[n];
        for(int i=0; i<n; i++){
            p[i] = {-abs(costs[i][0]-costs[i][1]), {costs[i][0], costs[i][1]}};
        }
        sort(p, p+n);
        int ans=0;
        int a=0,b=0;
        for(int i=0; i<n; i++){
            int z = p[i].first;
            int x = p[i].second.first;
            int y = p[i].second.second;
            
            //cout<<b; 
            if(a!=n/2 && b!=n/2){                
                if(x<y){
                    ans+=x;
                    a++;
                }
                else{
                    ans+=y;
                    b++;
                }
            }
            else{
                if(a==n/2){
                    ans+=y;
                }
                else{
                    ans+=x;
                }
            }
            //cout<<z<<":"<<ans<<" ";
            
        }
        return ans;
    }
};
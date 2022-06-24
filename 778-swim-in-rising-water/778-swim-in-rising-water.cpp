#define MAX 55
class Solution {
    int n;
    int move[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    bool vis[MAX][MAX];
public:
        
    bool check(vector<vector<int>> &grid, int m, int i=0, int j=0){
        if(i>=n || j>=n || i<0 || j<0)  return 0;
        if(grid[i][j]>m || vis[i][j])    return 0;
        if(i==n-1 && j==n-1)    return 1;
        vis[i][j]=1;
        for(int k=0; k<4; k++){
            if(check(grid, m, i+move[k][0], j+move[k][1])){
                return 1;
            }
        }
        return 0;
    }
    
    void clear(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)  vis[i][j]=0;
        }
    }
    
    
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l=0,h=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                h = max(h, grid[i][j]);
            }
        }
        
        int ans=0;
        while(l<=h){
            int m = l+(h-l)/2;
            clear();
            if(check(grid, m)){
                ans = m;
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans;
        
    }
};
#define MAX 110
class Solution {
    int n,m;
    int move[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    bool vis[MAX][MAX];
public:
        
    bool check(vector<vector<int>> &grid, int q, int p, int i=0, int j=0){
        if(i>=n || j>=m || i<0 || j<0)  return 0;
        if(grid[i][j]>q+p || grid[i][j]<p-q || vis[i][j])    return 0;
        if(i==n-1 && j==m-1)    return 1;
        vis[i][j]=1;
        for(int k=0; k<4; k++){
            if(check(grid, q,grid[i][j], i+move[k][0], j+move[k][1])){
                return 1;
            }
        }
        return 0;
    }
    
    void clear(){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)  vis[i][j]=0;
        }
    }
    
    int minimumEffortPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int l=0,h=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                h = max(h, grid[i][j]);
            }
        }
        
        int ans=0;
        while(l<=h){
            int q = l+(h-l)/2;
            clear();
            if(check(grid, q, grid[0][0])){
                ans = q;
                h = q-1;
            }
            else{
                l = q+1;
            }
        }
        return ans;
        
    }
};
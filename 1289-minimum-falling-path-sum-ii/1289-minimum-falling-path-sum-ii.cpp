#define MAX 200000
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans;
        for(int i=0; i<n; i++){
            int first = MAX, second = MAX;
            for(int j=0; j<m; j++){
                if(grid[i][j]<first){
                    second = first;
                    first = grid[i][j];
                }
                else if(grid[i][j] < second){
                    second = grid[i][j];
                }
            }
            ans = first;
            
            
            if(i!=n-1){
                for(int j=0; j<m; j++){
                    if(grid[i][j]==first){
                        grid[i+1][j]+= second;
                    }
                    else{
                        grid[i+1][j]+= first;
                    }
                }
            }
        }

        return ans;   
    }
};
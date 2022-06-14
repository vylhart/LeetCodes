class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i=0, j=m-1;
        int ans = 0;
        while(i<n && j>=0){
            while(j>=0 && grid[i][j]<0){
                j--;
            }
            //cout<<j;
            ans+= m-j-1;
            i++;
        }
        ans += (n-i)*m;
        return ans;
    }
};
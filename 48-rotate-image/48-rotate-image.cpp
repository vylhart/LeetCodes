class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> vis(n, vector<int>(n,0));
        for(int i=0; i<=n/2; i++){
            for(int j=0; j<=n/2; j++){
                if(!vis[i][j]){
                    int x1=i,y1=j;
                    int x2=n-1-j, y2=i;
                    int x3=n-1-i, y3=n-1-j;
                    int x4=j, y4= n-1-i;

                    vis[x1][y1]=vis[x2][y2]=vis[x3][y3]=vis[x4][y4]=1;
                    swap(mat[x1][y1], mat[x2][y2]);
                    swap(mat[x2][y2], mat[x3][y3]);
                    swap(mat[x3][y3], mat[x4][y4]);
                    //swap(mat[x4][y4], mat[x1][y1]);
                }
            }
        }
    }
};
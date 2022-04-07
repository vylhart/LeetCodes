class Solution {
public:
    int n,m;
    int move[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    bool safe(int i, int j){
        return i>=0 && j>=0 && i<n && j<m ; 
    }
    
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis){
        if(vis[i][j] || board[i][j]=='X')   return;
        vis[i][j]=1;
        for(int k=0; k<4; k++){
            int u = i+move[k][0];
            int v = j+move[k][1];
            if(safe(u,v))
                dfs(u,v,board, vis);
            
        }
    }
    
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,0));
        for(int i=0; i<n; i++){
            if(safe(i,0))
                dfs(i,0,board,vis);
            if(safe(i,m-1))
                dfs(i,m-1,board,vis);
        }
        for(int i=0; i<m; i++){
            if(safe(0,i))
                dfs(0,i,board,vis);
            if(safe(n-1,i))
                dfs(n-1,i,board,vis);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};
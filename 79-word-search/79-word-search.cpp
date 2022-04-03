class Solution {
public:
    int move[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int n,m,p;
    string w;
    
    bool safe(int i, int j, int k, vector<vector<char>>& board, vector<vector<bool>>& vis){
        return i>=0 && j>=0 && i<n && j<m && w[k]==board[i][j] && !vis[i][j];
    }
    
    bool dfs(int i, int j, int k, vector<vector<char>>& board, vector<vector<bool>>& vis){
        //cout<<w[k];
        vis[i][j]=1;
        if(k+1==p)    return 1;
        for(int l=0; l<4; l++){
            int u = i+move[l][0];
            int v = j+move[l][1];
            if(safe(u,v,k+1, board,vis) && dfs(u,v,k+1,board, vis)){
                return 1;
            }
        }
        vis[i][j]=0;
        return 0;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        p = word.length();
        w = word;
        //cout<<p;
        vector<vector<bool>> vis(n, vector<bool>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(safe(i,j,0, board,vis) && dfs(i,j,0,board, vis)){
                    return 1;
                }
            }
        }
        return 0;
    }
};
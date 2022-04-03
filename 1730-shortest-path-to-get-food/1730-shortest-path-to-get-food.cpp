class Solution {
public:
    int move[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int n,m;
    class Node{
        public:
        int x,y,d;
        Node(int xx, int yy, int dd){
            x=xx;y=yy;d=dd;
        }
    };
    
    bool safe(int i, int j,vector<vector<char>>& board, vector<vector<bool>>& vis){
        return i>=0 && j>=0 && i<n && j<m && 'X' != board[i][j] && !vis[i][j];
    }

    
    int getFood(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,0));
        queue<Node*> q;
        Node *node;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='*'){
                    node = new Node(i,j,0);
                }
            }
        }
        q.push(node);
        vis[node->x][node->y]=1;
        while(!q.empty()){
            int x = q.front()->x;
            int y = q.front()->y;
            int d = q.front()->d;
            //cout<<x<<y<<endl;
            q.pop();
            if(board[x][y]=='#')    return d;
        
            for(int l=0; l<4; l++){
                int u = x+move[l][0];
                int v = y+move[l][1];
                if(safe(u,v, board,vis)){
                    node = new Node(u,v,d+1);
                    vis[u][v]=1;
                    q.push(node);
                }
            }
        }
        return -1;
        
        
        
        
        
    }
};
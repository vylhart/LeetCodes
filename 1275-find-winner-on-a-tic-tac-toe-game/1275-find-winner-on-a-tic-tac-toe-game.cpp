class Solution {
public:
    int grid[3][3];
    
    int check(){
       int move[4][2][2] = {
           {{0,1},{0,-1}},
           {{1,0},{-1,0}},
           {{-1,-1},{1,1}},
           {{-1,1},{1,-1}}
       };
        
        int x=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int val = grid[i][j];
                if(val!=0) x++;
                for(int k=0; k<4; k++){
                    int c=0;
                    for(int l=0; l<2; l++){
                        int u = i+move[k][l][0];
                        int v = j+move[k][l][1];
                        if(u>=0 && v>=0 && u<3 && v<3 && grid[u][v]==val){
                            c++;
                        }
                    }
                    if(c==2 && val>0)    return val;
                }
            }
        }
        return x==9? 3:4;
    }
    
    
    string tictactoe(vector<vector<int>>& moves) {
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                grid[i][j]=0;
            }
        }
        int turn=0;
        for(auto i:moves){
            grid[i[0]][i[1]] = turn+1;
            turn = 1-turn;
        }
        int ans = check();
        cout<<ans;
        switch(ans){
            case 1: return "A";
            case 2: return "B";
            case 3: return "Draw";
            case 4: return "Pending";
        }
        return "-1";
        
    }
};
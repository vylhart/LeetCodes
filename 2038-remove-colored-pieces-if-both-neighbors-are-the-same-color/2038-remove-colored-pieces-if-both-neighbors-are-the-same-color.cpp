class Solution {
public:
    bool winnerOfGame(string colors) {
        int A=0, B=0;
        for(int i=1; i+1<colors.size(); i++){
            if(colors[i]==colors[i-1] && colors[i]==colors[i+1]){
                if(colors[i]=='A')  A++;
                else    B++;
            }
        }
        return A>B;
    }
};
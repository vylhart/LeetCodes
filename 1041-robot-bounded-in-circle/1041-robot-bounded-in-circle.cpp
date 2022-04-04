class Solution {
public:
    bool isRobotBounded(string inst) {
        inst += inst+inst+inst;
        int pos[] = {0,0,0,0};
        int dir = 0;
        for(char c: inst){
            switch(c){
                case 'G':
                    pos[dir]++;
                    break;
                case 'L':
                    dir = (dir+3)%4;
                    break;
                case 'R':
                    dir = (dir+1)%4;
                    break;
            }
        }
        cout<<pos[0]<<pos[1]<<pos[2]<<pos[3]<<endl;
        return pos[0]==pos[2] && pos[1]==pos[3]; 
    }
};
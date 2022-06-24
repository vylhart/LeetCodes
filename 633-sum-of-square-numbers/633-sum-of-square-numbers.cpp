class Solution {
public:
    bool judgeSquareSum(int c) {
        long l=0, h=sqrt(c);
        while(l<=h){
            while(l*l+h*h>c){
                h--;
            }
            if(l*l+h*h==c)  return 1;
            l++;
        }
        return 0;
    }
};
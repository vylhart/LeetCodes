class Solution {
public:
    
    
    bool isPerfectSquare(int num) {
        int l=0, h=num;
        while(l<=h){
            long m = l + (h-l)/2;
            if(m*m == num)  return 1;
            else if(m*m < num)  l=m+1;
            else    h=m-1;
        }
        return 0;
    }
};
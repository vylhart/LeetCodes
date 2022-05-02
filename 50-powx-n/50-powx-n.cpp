class Solution {
public:
    
    
    double myPow(double x, int n) {
        bool sign = 1;
        if(n<0) sign = 0;
        double ans=1;
        while(n){
            if(n&1) ans *= x;
            x *= x;
            n /= 2;
        }
        return sign ? ans:1/ans;
    }
};

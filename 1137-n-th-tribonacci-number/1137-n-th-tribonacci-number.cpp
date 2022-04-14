class Solution {
public:
    int tribonacci(int n) {
        int a=0,b=1,c=1;
        for(int i=3; i<=n; i++){
            int x = a+b+c;
            a=b;
            b=c;
            c=x;
        }
        switch(n){
            case 0:
                return 0;
            case 1:
                return 1;
            default:
                return c;
        }
        return -1;
    }
};
class Solution {
public:
    int trailingZeroes(int n) {
        int d = 5;
        int c = 0;
        while(d<=n){
            c += n/d;
            d *= 5;
        }
        return c;
    }
};
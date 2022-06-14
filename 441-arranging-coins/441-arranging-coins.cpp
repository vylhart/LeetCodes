class Solution {
public:
    int arrangeCoins(int n) {
        int l=1, h=n;
        int ans = 1;
        while(l<=h){
            long m = l + (h-l)/2;
            if(m*(m+1)<=(long)2*n){
                ans = m;
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return ans;
    }
};
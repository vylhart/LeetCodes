class Solution {
public:
    long count(long n, long x){
        n++;
        x = 1<<x;
        return (n/(2*x))*x + max(0L, (n%(2*x)-x));
    }
    
    int rangeBitwiseAnd(int left, int right) {
        long m = right-left+1L;
        int ans = 0;
        for(int i=0; i<31; i++){
            int a = count(right, i);
            int b = count(left-1, i);
            ans |= a-b == m ? (1<<i): 0;
        }
        return ans;
    }
};
class Solution {
public:
    bool check(int x, int n, vector<int> &q){
        for(int i: q){
            n -= i%x==0 ? i/x : (i/x)+1;
        }
        return n>=0;
    }
    
    int minimizedMaximum(int n, vector<int>& q) {
        int l=1, h = (int)1e5;
        int ans = h;
        while(l<=h){
            int m = l+(h-l)/2;
            if(check(m, n, q)){
                h = m-1;
                ans = m;
            }
            else{
                l = m+1;
            }
        }
        return ans;
    }
};
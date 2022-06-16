class Solution {
public:
    bool check(vector<int> &r, int x, int k){
        for(int i: r)   k-= i/x;
        return k<=0;
    }
    
    int maxLength(vector<int>& r, int k) {
        int n = r.size();
        int l = 1, h = r[0];
        for(int i: r) h = max(h, i);
        int ans = 0;
        while(l<=h){
            int m = l+(h-l)/2;
            if(check(r, m, k)){
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
class Solution {
public:
    bool check(vector<int> &w, int d, int k){
        int curr=0;
        for(int i:w){
            if(i>k) return 0;
            if(curr+i<=k){
                curr+=i;
            }
            else{
                curr = i;
                d--;
            }
        }
        return d>=1;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int l=1, h=0;
        for(int i:w)    h+= i;
        int ans = -1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(check(w,days,m)){
                ans = m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};
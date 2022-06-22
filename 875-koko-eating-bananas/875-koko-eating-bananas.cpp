class Solution {
public:
    bool check(vector<int> &p, int h, int k){
        for(int i:p){
            h -= i%k==0 ? (i/k) : (i/k)+1;
        }
        return h>=0;
    }
    int minEatingSpeed(vector<int>& piles, int hr) {
        int l=1, h=0;
        for(int i:piles)h = max(h,i);
        int ans = -1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(check(piles, hr, m)){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};
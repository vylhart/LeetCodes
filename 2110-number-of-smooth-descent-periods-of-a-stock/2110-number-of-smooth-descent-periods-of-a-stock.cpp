class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long prev=-1, ans=0, prevC=0;
        for(int i: prices){
            if(prev-1 == i){
                prevC++;
                ans+=prevC;
            }
            else{
                prevC=1;
                ans+=prevC;
            }
            prev=i;
        }
        return ans;
    }
};
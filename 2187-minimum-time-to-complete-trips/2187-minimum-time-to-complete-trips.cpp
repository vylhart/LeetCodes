class Solution {
public:
    
    bool check(vector<int> &time, long long t, int trips){
        long long sum=0;
        for(long long i: time){
            sum += t/i;
        }
        return sum>=trips;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long l=0, h=1e14;
        long long ans = h;
        while(l<=h){
            long long m = l + (h-l)/2;
            if(check(time, m, totalTrips)){
                ans = m;
                h = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans;
    }
};
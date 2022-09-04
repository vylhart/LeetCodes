class Solution {
    int n;
    vector<long> psum;
public:
    vector<int> maxWindow(vector<int>& nums, int k) {
        vector<int> v;
        deque<int> q;
        for(int i=0; i<k-1; i++){
            while(!q.empty() && nums[i]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        for(int i=k-1; i<n; i++){
            while(!q.empty() && i-k>=q.front()){
                q.pop_front();
            }
            while(!q.empty() && nums[i]>nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            v.push_back(nums[q.front()]);
        }
        return v;        
    }
    
    
    bool check(vector<int>& charge, long long budget, int k){
        vector<int> maxWin = maxWindow(charge, k);
        for(int i=0; i+k-1<n; i++){
            long long max = maxWin[i];
            long long sum = psum[i+k-1] - (i-1>=0 ? psum[i-1]: 0);
            if(max+k*sum <= budget){
                return 1;
            }
        }
        return 0;
    }
    
    int maximumRobots(vector<int>& charge, vector<int>& run, long long budget) {
        n = charge.size();
        long sum = 0;
        for(int i: run){
            sum+= i;
            psum.push_back(sum);
        }
        
        int l=1, h=n;
        int ans = 0;
        while(l<=h){
            int k = l+(h-l)/2;
            if(check(charge, budget, k)){
                ans = k;
                l=k+1;
            }
            else{
                h=k-1;
            }
        }
        return ans;
    }
};
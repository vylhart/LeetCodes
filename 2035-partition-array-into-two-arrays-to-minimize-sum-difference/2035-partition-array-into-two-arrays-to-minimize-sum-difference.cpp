class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        n /=2;
        int ans = INT_MAX;
        vector<vector<int>> left(n+1);
        
        for(int i=0; i<(1<<n); i++){
            int tmp = 0;
            int c =0 ;
            for(int j=0; j<n; j++){
                if(i&(1<<j)){
                    c++;
                    tmp += nums[j];
                }
                else{
                    tmp -= nums[j]; 
                }
            }
            left[c].push_back(tmp);
        }
        
        for(int i=0; i<=n; i++){
            sort(left[i].begin(), left[i].end());
        }
        
        
        for(int i=0; i<(1<<n); i++){
            int tmp = 0;
            int c =0 ;
            for(int j=0; j<n; j++){
                if(i&(1<<j)){
                    tmp += nums[n+j];
                    c++;
                }
                else{
                    tmp -= nums[n+j]; 
                }
            }
            
            auto it = lower_bound(left[c].begin(), left[c].end(), tmp);
            if(it!=left[c].end()){
                ans = min(ans, abs(tmp - *it));
            }
            if(it!=left[c].begin()){
                it--;
                ans = min(ans, abs(tmp - *it));
            }
            
        }
        
        
        
        return ans;
    }
};
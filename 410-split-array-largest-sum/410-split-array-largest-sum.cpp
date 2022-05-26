#define MAX 1000000007
class Solution {
public:
    bool find(vector<int> &nums, int x, int m){
        int n=nums.size();
        int sum=0;
        int cnt=1;
        for(int i=0; i<n; i++){
            if(nums[i]>x){
                return false;
            }
            if(sum+nums[i]<=x){
                sum+=nums[i];
            }            
            else{
                sum=nums[i];
                cnt++;
            }
        }
        return cnt<=m;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int sum=0;
        for(int i:nums) sum+=i;
        
        int l=0,h=sum,ans=sum;
        while(l<=h){
            int mid = (l+h)/2;
            if(find(nums, mid, m)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
        
        
    }
};
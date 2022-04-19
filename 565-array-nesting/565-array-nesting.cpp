class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, 0);
        int ans = 0;
        for(int i=0; i<n; i++){
            int z=0;
            if(vis[i]==0){
                int k=nums[i];
                z++;
                while(k!=i){
                    z++;
                    vis[k]=1;
                    k = nums[k];
                }
                vis[i]=1;
            }
            ans = max(ans, z);
        }
        return ans;
    }
};
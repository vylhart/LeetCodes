class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int ans=0;
        for(int i:nums) map[i]++;
        for(auto i: map){
            int x = i.first;
            if(k>0 && map.find(x+k)!=map.end()){
                ans++;
            }
            else if(k==0 && map[x]>1){
                ans++;
            }
        }
        return ans;
    }
};
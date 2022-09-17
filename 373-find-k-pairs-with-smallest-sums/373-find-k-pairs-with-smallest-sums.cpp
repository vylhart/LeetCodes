class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<pair<int,pair<int,int>>> q;
        for(int i=0; i<n; i++){
            q.push({-(nums1[i]+nums2[0]), {i,0}});
        }
        
        while(ans.size()!=k && !q.empty()){
            auto x = q.top().second;
            q.pop();
            ans.push_back({nums1[x.first], nums2[x.second]});
            if(x.second+1<m){
                q.push({-(nums1[x.first]+nums2[x.second+1]), {x.first, x.second+1}});
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();      
        
        vector<int> ans;
        ans.push_back(0);
        for(int j=0; j<n; j++){
            int s = ans.size();
            
            priority_queue<pair<int,pair<int,int>>> q;
            for(int i=0; i<min(k,m); i++){
                q.push({-(mat[j][i]+ans[0]), {i,0}});
            }

            vector<int> tmp;
            
            while(tmp.size()!=k && !q.empty()){
                auto x = q.top().second;
                q.pop();
                tmp.push_back(mat[j][x.first]+ans[x.second]);
                if(x.second+1<s){
                    q.push({-(mat[j][x.first]+ans[x.second+1]), {x.first, x.second+1}});
                }
            }
            ans = tmp;
            
        }
        
        return ans[k-1];
    }
};
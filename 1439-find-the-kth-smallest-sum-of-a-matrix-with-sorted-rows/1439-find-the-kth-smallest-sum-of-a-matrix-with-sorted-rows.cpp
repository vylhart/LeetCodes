class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int kk) {
        int n = mat.size(), m = mat[0].size();
        vector<int> ans;
        ans.push_back(0);
        
        
        priority_queue<int> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int k=0; k<ans.size(); k++){
                    q.push(mat[i][j] + ans[k]);
                    if(q.size()>kk)  q.pop();
                }
            }
            ans.clear();
            while(!q.empty()) {
                ans.push_back(q.top());
                q.pop();
            } 
        }
        return ans[0];
    }
};
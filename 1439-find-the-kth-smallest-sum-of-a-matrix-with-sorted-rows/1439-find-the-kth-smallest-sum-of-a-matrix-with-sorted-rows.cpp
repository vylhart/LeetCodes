class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int kk) {
        int n = mat.size(), m = mat[0].size();      
        
        
        priority_queue<int> q;
        q.push(0);
        
        for(int i=0; i<n; i++){
            priority_queue<int> p;
            while(!q.empty()){
                for(int j=0; j<m; j++){
                    p.push(q.top()+mat[i][j]);
                    if(p.size()>kk) p.pop();
                }
                q.pop();
            }
            q = p;
        }
        return q.top();
    }
};
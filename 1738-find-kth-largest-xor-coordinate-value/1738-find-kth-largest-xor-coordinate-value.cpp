class Solution {
public:
    int kthLargestValue(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<int> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i-1>=0 && j-1>=0)    mat[i][j]^=mat[i-1][j-1];
                if(i-1>=0)    mat[i][j]^=mat[i-1][j];
                if(j-1>=0)    mat[i][j]^=mat[i][j-1];
                q.push(-mat[i][j]);
                if(q.size()>k)  q.pop();
            }
        }
        return -q.top();
    }
};
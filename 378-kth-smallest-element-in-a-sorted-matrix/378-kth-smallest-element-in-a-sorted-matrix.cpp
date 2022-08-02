class Solution {
    int n,m;
public:
    int count(vector<vector<int>> &mat, int k){
        int i=n-1, j=0, ans=0;
        while(i>=0){
            while(j<m && mat[i][j]<=k)   j++;
            ans += j;
            i--;
        }
        return ans;
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        n  = mat.size(); m = mat[0].size();
        int l = mat[0][0], h = mat[n-1][n-1];
        int ans = -1;
        while(l<=h){
            int x = l+(h-l)/2;
            int c = count(mat, x);
            //cout<<x<<c<<endl;
            if(c<k){
                l = x+1;
            }
            else{
                h = x-1;
                ans = x;
            }
        }
        return ans;
    }
};
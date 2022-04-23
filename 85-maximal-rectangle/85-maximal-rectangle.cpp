class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> s;
        int n = h.size();
        int ans=0;
        for(int i=0; i<n; i++){
            while(!s.empty() && h[s.top()]>=h[i]){
                int calc = s.top();
                s.pop();
                int prev = !s.empty() ? s.top()+1:calc; 
                ans = max(ans, (i-prev)*h[calc]);
            }
            s.push(i);
        }
        return ans;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> h(m+2, 0);
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='1'){
                    h[j+1]+=1;
                }
                else{
                    h[j+1]=0;
                }
            }
            ans = max(ans, largestRectangleArea(h));
        }
        return ans;
    }
};
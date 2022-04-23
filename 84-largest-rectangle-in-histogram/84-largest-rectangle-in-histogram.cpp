class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        h.insert(h.begin(),0);
        h.push_back(0);
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
};
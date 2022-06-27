class Solution {
public:
    vector<int> findBuildings(vector<int>& h) {
        stack<int> s;
        for(int i=0; i<h.size(); i++){
            while(!s.empty() && h[i]>=h[s.top()])  s.pop();
            s.push(i);
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        vector<int> ans(t.size(), 0);
        for(int i=0; i<t.size(); i++){
            while(!s.empty() && t[i]>t[s.top()]){
                ans[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};